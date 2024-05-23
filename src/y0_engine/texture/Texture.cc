#include <iostream>
#include <SOIL/SOIL.h>
#include <GL/glew.h>

#include "y0_engine/texture/Texture.h"

Texture::Texture()
  : mTextureID(0),
    width_(0),
    height(0) {
}

Texture::~Texture() {
}

bool Texture::LoadTexture(const std::string &file_neame) {
  int channels = 0;

  unsigned char *image = SOIL_load_image(fileName.c_str(),
      &mWidth, &mHeight, &channels, SOIL_LOAD_AUTO);

  if (image == nullptr) {
    std::cerr << "failed to load texture: " << fileName <<  " " << SOIL_last_result();
    return false;
  }

  int format = channels == 4 ? GL_RGBA : GL_RGB;

  glGenTextures(1, &texture_id_);
  glBindTexture(GL_TEXTURE_2D, texture_id);

  glTexImage2D(GL_TEXTURE_2D, 0, format, width_, height_,
               0, format,GL_UNSIGNED_BYTE, image);

  SOIL_free_image_data(image);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  return true;
}

void Texture::UnloadTheTexture() {
  glDeleteTextures(1, &texture_id_);
}

void Texture::LetActiveTheTexture() {
  glBindTexture(GL_TEXTURE_2D, texture_id_);
}
