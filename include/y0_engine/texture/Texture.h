#ifndef Y0_ENGINE_INCLUDE_Y0_EINGINE_TEXTURE_TEXTURE_H
#define Y0_ENGINE_INCLUDE_Y0_EINGINE_TEXTURE_TEXTURE_H

#include <string>

class Texture {
public:
	Texture();
	~Texture();
	
	bool LoadTexture(const std::string &file_name);
	void UnloadTexture();
	
	void LetActiveTheTexture();

	inline int GetWidth() const { return width_; }
	inline int GetHeight() const { return height_; }

private:
	unsigned int texture_id_;
	int width_;
	int height_;
};

#endif
