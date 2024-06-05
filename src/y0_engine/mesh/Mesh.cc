#include <fstream>
#include <sstream>
#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "y0_core/Log/Logger.h"
#include "y0_core/math/Math.h"
#include "y0_engine/mesh/Mesh.h"
#include "y0_engine/rendering/Renderer.h"
#include "y0_engine/texture/Texture.h"
#include "y0_engine/object/VertexArray.h"

namespace y0_engine {
  /**
   * @brief constructor
   */
  Mesh::Mesh()
    : radius_(0.0f),
      spec_power_(100.0f) {
  }

  /**
   * @brief destructor
   */
  Mesh::~Mesh() {
  }

  /**
   * @brief load mesh data defined as json with boost::property_tree
   *
   * @param file_name
   * @param renderer
   *
   * @return 
   */
  bool Mesh::LoadMesh(const std::string &file_name, Renderer *renderer)
  {
    std::ifstream file(file_name);
    if (!file.is_open()) {
      LOG_ERROR(std::string("File not found: Mesh ") + file_name);
      return false;
    }

    std::stringstream file_stream;
    file_stream << file.rdbuf();
    std::string contents = file_stream.str();

    std::istringstream json_stream(contents);
    boost::property_tree::ptree doc;
    try {
      boost::property_tree::read_json(json_stream, doc);
    }
    catch (const boost::property_tree::json_parser_error& e) {
      LOG_ERROR(std::string("Mesh ") + file_name + std::string(" is not valid json ") + e.what());
      return false;
    }

    int ver = doc.get<int>("version", -1);
    if (ver != 1) {
      LOG_ERROR(std::string("Mesh ") + file_name + std::string(" not version 1"));
      return false;
    }

    shader_name_ = doc.get<std::string>("shader", "");

    // Skip the vertex format/shader for now
    size_t vertSize = 8;

    // Load textures
    auto texturesNode = doc.get_child_optional("textures");
    if (!texturesNode || texturesNode->empty()) {
      LOG_ERROR(std::string("Mesh ") + file_name + std::string(" has no textures. there should be at least one."));
      return false;
    }

    spec_power_ = doc.get<float>("specularPower", 100.0f);

    for (const auto& item : *texturesNode)
    {
      std::string texture_name = item.second.get_value<std::string>();
      std::unique_ptr<Texture> t = renderer->GetTexture(texture_name);
      if (t.get() == nullptr)
      {
        t = renderer->GetTexture("Assets/Texture.png");
      }
      textures_.emplace_back(t.get());
    }

    // Load in the vertices
    auto vertsNode = doc.get_child_optional("vertices");
    if (!vertsNode || vertsNode->empty()) {
      LOG_ERROR(std::string("Mesh ") + file_name + std::string(" has no vertices."));
      return false;
    }

    std::vector<float> vertices;
    vertices.reserve(vertsNode->size() * vertSize);
    radius_ = 0.0f;

    for (const auto &item : *vertsNode) {
      auto vert = item.second;
      if (vert.size() != 8) {
        LOG_ERROR(std::string("Unexpected vertex format for ") + file_name);
        return false;
      }

      Vector3 pos(vert.get<double>("0"), vert.get<double>("1"), vert.get<double>("2"));
      radius_ = Math::Max(radius_, pos.SquareLength());

      for (size_t i = 0; i < vert.size(); ++i) {
        vertices.emplace_back(vert.get<float>(std::to_string(i)));
      }
    }

    radius_ = Math::Sqrt(radius_);

    // Load in the indices
    auto indicesNode = doc.get_child_optional("indices");
    if (!indicesNode || indicesNode->empty()) {
      LOG_ERROR(std::string("Mesh ") + file_name + std::string(" has no indices"));
      return false;
    }

    std::vector<unsigned int> indices;
    indices.reserve(indicesNode->size() * 3);
    for (const auto& item : *indicesNode) {
      auto ind = item.second;
      if (ind.size() != 3) {
        LOG_ERROR(std::string("Invalid indices for ") + file_name);
        return false;
      }

      for (size_t i = 0; i < 3; ++i) {
        indices.emplace_back(ind.get<unsigned int>(std::to_string(i)));
      }
    }

    vertex_array_ = std::make_unique<VertexArray>(
                      3,
                      vertices.data(),
                      static_cast<unsigned>(vertices.size()) / vertSize,
                      indices.data(),
                      static_cast<unsigned>(indices.size()));
    return true;
  }

  /**
   * @brief free vertex array
   */
  void Mesh::UnloadTheMesh() {
    vertex_array_.reset();
  }

  /**
   * @brief return texture data
   *
   * @param index
   *
   * @return 
   */
  Texture* Mesh::GetTexture(size_t index) {
    if (index < textures_.size())
      return textures_[index];

    return nullptr;
  }
} // namespace y0_engine
