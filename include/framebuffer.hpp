#pragma once

#include <string>
#include <cstdint>
#include <linux/fb.h>

namespace framebuffer {

	enum FBCode {
		FB_OK = 0,
		FB_NO_ACCESS,
		FB_ERROR_VARIABLE_INFO,
		FB_ERROR_FIXED_INFO,
		FB_ERROR_FBIOGETCMAP,
		FB_ERROR_FBIOGET_VSCREENINFO,
		FB_ERROR_FBIOGET_FSCREENINFO,
		FB_ERROR_MAP_FBDEV_TO_MEMORY,
		FB_ERROR_OPEN
	};

	struct FBState {

		private:
			FBCode _code;
			std::string _string;

		public:
			const FBCode code() { return this -> _code; }
			const std::string string() { return this -> _string; }

			FBState(FBCode code, std::string msg = "") : _code(code), _string(msg) {};

			constexpr bool operator ==(FBCode code) {
				return this -> _code == code;
			}
	};

	extern std::string fb_dev;

	extern int fb_fd;
	extern int fb_offset;
	extern char* fb_buf;
	extern struct fb_var_screeninfo vinfo;
	extern struct fb_fix_screeninfo finfo;
	extern struct fb_var_screeninfo oinfo;

	extern int prev_tty_ndx;
	extern int prev_kdmode;
	extern int tty;
	extern int tty_ndx;

	void reset();
	void set_coordinates(int &x, int &y, int width, int height);
	void set_color(long int location, int32_t rgba);
	FBState open_buffer();
	FBState exit_console();

	FBState init();
	void deinit();
}
