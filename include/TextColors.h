/*
    @headerfile     TextColors.h
    @author         Ahmad Mzayek
    @date           Thursday, July 4th, 2024
    @brief          This header file defines Macros for Colored Text Output in the terminal.
    @details        The Macros defined in this file can be used to print text in various colors and styles
    @details        using ANSI escape codes. Each color has both a Regular and a Bold version.
    @example        fprintf(stdout, RED "This text is red." DEFAULT_COLOR "\n");
    @note           Ensure to reset the text color to the default color using 'DEFAULT_COLOR' after using
    @note           any color macro to avoid unwanted text color changes in subsequent output.
    @note           Compatibility is NOT guaranteed across all terminal emulators and systems.
*/

#ifndef __TEXT_COLORS_H_
#define __TEXT_COLORS_H_

#define DEFAULT_COLOR "\033[0m"
#define RED "\033[0;31m"
#define RED_BOLD "\033[1;31m"
#define GREEN "\033[0;32m"
#define GREEN_BOLD "\033[1;32m"
#define YELLOW "\033[0;33m"
#define YELLOW_BOLD "\033[1;33m"
#define BLUE "\033[0;34m"
#define BLUE_BOLD "\033[1;34m"
#define MAGENTA "\033[0;35m"
#define MAGENTA_BOLD "\033[1;35m"
#define CYAN "\033[0;36m"
#define CYAN_BOLD "\033[1;36m"

#endif // __TEXT_COLORS_H_