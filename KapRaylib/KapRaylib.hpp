/*
** EPITECH PROJECT, 2022
** KapRaylib
** File description:
** KapRaylib
*/

#ifndef KAPRAYLIB_HPP_
#define KAPRAYLIB_HPP_

#define KAPRAYLIB_VERSION_MAJOR 0
#define KAPRAYLIB_VERSION_MINOR 100
#define KAPRAYLIB_VERSION "0.100"

#define IS_KAPRAYLIB_VERSION(x, y) (KAPRAYLIB_VERSION_MAJOR != x)? false : (KAPRAYLIB_VERSION_MINOR != y)? false : true
#define IS_MAX_KAPRAYLIB_VERSION(x, y) (KAPRAYLIB_VERSION_MAJOR < x)? true : (KAPRAYLIB_VERSION_MAJOR > x)? false : (KAPRAYLIB_VERSION_MINOR <= y)? true : false
#define IS_MIN_KAPRAYLIB_VERSION(x, y) (KAPRAYLIB_VERSION_MAJOR < x)? false : (KAPRAYLIB_VERSION_MAJOR > x)? true : (KAPRAYLIB_VERSION_MINOR < y)? false : true

#ifndef KAPRAYLIB_GRAPHICAL_HPP_
    #include "Graphical/RaylibGraphical.hpp"
#endif

#ifndef KAPRAYLIB_ENCAPSULATION_HPP_
    #include "Encapsulation/RaylibEncapsulation.hpp"
#endif

#ifndef KAPRAYLIB_DRAWUI_HPP_
    #include "DrawSystem/DrawUI.hpp"
#endif

#ifndef KAPRAYLIB_CACHE_HPP_
    #include "Cache/RaylibCache.hpp"
#endif

#endif /* !KAPRAYLIB_HPP_ */
