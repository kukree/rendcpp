#ifndef REND_H
#define REND_H

#include <iostream>
#include <vector>
#include <unistd.h>


namespace rend
{
    class Screen
    {
    private:
        // Screen size and Frames Per Second
        int height, width, FPS;
        float frame_time;

        // Size and position variables
        winsize terminal_size;
        unsigned short x_center = terminal_size.ws_col / 2;
        unsigned short y_center = terminal_size.ws_row / 2;
        std::vector<std::vector<char>> frame;
        std::vector<std::vector<std::vector<char>>> frame_list;

        void render_frame(std::vector<std::vector<char>> frame);

    public:
        Screen(unsigned int scr_height, unsigned int scr_width, unsigned int scr_FPS, unsigned int frames_count);
        unsigned short get_x_center();
        unsigned short get_y_center();
        void fill_frame(unsigned int frame_index, char fill_sym='#');
        void edit_frame(unsigned int frame_index, unsigned int x, unsigned int y, char sym=' ');
        void render(int repeat=1);
    };
}

#endif