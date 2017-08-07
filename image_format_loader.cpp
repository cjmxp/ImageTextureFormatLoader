/*************************************************************************/
/*  image_format_loader.h                                                */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                    http://www.godotengine.org                         */
/*************************************************************************/
/* Copyright (c) 2007-2017 Juan Linietsky, Ariel Manzur.                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#include "image_format_loader.h"
#include <scene/resources/texture.h>
#include <core/io/image_loader.h>

RES ResourceFormatLoaderImageTexture::load(const String &p_path, const String &p_original_path, Error *r_error) {

	Ref<ImageTexture> tex;
	tex.instance();

	Ref<Image> img;
	img.instance();
	if (OK != img->load(p_path))
		return RES();

	tex->create_from_image(img);
	return tex;
}

void ResourceFormatLoaderImageTexture::get_recognized_extensions(List<String> *p_extensions) const {

	ImageLoader::get_recognized_extensions(p_extensions);
}

bool ResourceFormatLoaderImageTexture::handles_type(const String &p_type) const {

	return p_type == "ImageTexture";
}

String ResourceFormatLoaderImageTexture::get_resource_type(const String &p_path) const {

	if (ImageLoader::recognize(p_path.get_extension().to_lower()))
		return "ImageTexture";
	return "";
}
