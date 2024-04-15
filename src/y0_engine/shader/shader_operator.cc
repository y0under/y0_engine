#include "../../../include/y0_engine/shader/shader_operator.h"

#include <fstream>
#include <iostream>
#include <sstream>

shader_operator::shader_operator() {
}

shader_operator::~shader_operator() {
}

bool shader_operator::is_success_compile(GLuint shader) {
  GLint compile_result;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_result);
  if (compile_result == GL_TRUE)
    return true;

  char buffer[512];
  std::memset(buffer, 0, 512);
  glGetShaderInfoLog(shader, 511, nullptr, buffer);
  // TODO: out put log
  std::cerr << buffer << std::endl;

  return false;
}

bool shader_operator::is_valid_program(GLuint shader) {
  GLint link_result;
  glGetProgramiv(shader, GL_LINK_STATUS, &link_result);
  if (link_result == GL_TRUE)
    return true;

  char buffer[512];
  std::memset(buffer, 0, 512);
  glGetProgramInfoLog(shader, 511, nullptr, buffer);
  // TODO: out put log
  std::cerr << buffer << std::endl;
  return false;
}

bool shader_operator::compile_shader(const std::string &file_name,
                                     GLenum shader_type,
                                     GLuint &out_shader) {
  std::ifstream shader_file(file_name);
  if (!shader_file.is_open())
    return false;

  // get stream buffer object
  std::stringstream sstream;
  sstream << shader_file.rdbuf();

  // get contents
  std::string s = sstream.str();
  const char *contents = s.c_str();

  out_shader = glCreateShader(shader_type);
  glShaderSource(out_shader, 1, &contents, nullptr);
  glCompileShader(out_shader);

  if (!is_success_compile(out_shader))
    return false;

  return true;
}

bool shader_operator::load_shader(const std::string &vertex_shader_file_name,
                                  const std::string &fragment_shader_file_name) {
  if (!compile_shader(vertex_shader_file_name, GL_VERTEX_SHADER, vertex_shader_id_) ||
      !compile_shader(fragment_shader_file_name, GL_FRAGMENT_SHADER, fragment_shader_id_))
    return false;

  shader_program_id_ = glCreateProgram();
  glAttachShader(shader_program_id_, vertex_shader_id_);
  glAttachShader(shader_program_id_, fragment_shader_id_);
  glLinkProgram(shader_program_id_);

  if (!is_valid_program(shader_program_id_))
    return false;
  return true;
}

void shader_operator::unload_shader() {
  glDeleteProgram(shader_program_id_);
  glDeleteProgram(vertex_shader_id_);
  glDeleteProgram(fragment_shader_id_);
}

void shader_operator::set_target_shader() {
  glUseProgram(shader_program_id_);
}
