#include <iostream>
#include <GL/glew.h>
#include <opencv2/opencv.hpp>

#include "y0_engine/texture/Texture.h"

Texture::Texture()
  : texture_id_(0),
    width_(0),
    height_(0) {
}

Texture::~Texture() {
  UnloadTexture();
}

bool Texture::LoadTexture(const std::string &file_name) {
  // load image
  cv::Mat image = cv::imread(file_name, cv::IMREAD_UNCHANGED);
  if (image.empty()) {
    std::cerr << "Failed to load texture: " << file_name << std::endl;
    return false;
  }

  // set format following the number of chanel.
  int channels = image.channels();
  int format = channels == 4 ? GL_RGBA : GL_RGB;

  width_ = image.cols;
  height_ = image.rows;

  glGenTextures(1, &texture_id_);
  glBindTexture(GL_TEXTURE_2D, texture_id_);

  glTexImage2D(GL_TEXTURE_2D, 0, format, width_, height_, 0, format, GL_UNSIGNED_BYTE, image.data);

  // let active linear filtering
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  return true;
}

void Texture::LetActiveTheTexture() {
  glBindTexture(GL_TEXTURE_2D, texture_id_);
}

void Texture::UnloadTexture() {
  if (texture_id_ == 0)
    return;
  glDeleteTextures(1, &texture_id_);
  texture_id_ = 0;
}
