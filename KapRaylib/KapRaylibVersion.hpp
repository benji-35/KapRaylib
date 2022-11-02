/*
** EPITECH PROJECT, 2022
** KapRaylib
** File description:
** KapRaylibVersion
*/

#ifndef KAPRAYLIB_VERSION_HPP_
#define KAPRAYLIB_VERSION_HPP_

/**
 * @brief The beta version of KapRaylib
 * if KAPRAYLIB_BETA is defined, the version will be the beta version but that can be unstable
 */
#ifndef KAPRAYLIB_BETA_OW
    #define KAPRAYLIB_BETA false
#else
    #define KAPRAYLIB_BETA KAPRAYLIB_BETA_OW
#endif

/**
 * @brief active 3D drawing system
 * 
 */
#ifndef KAPRAYLIB_3D_ACTIVE_OW
    #define KAPRAYLIB_3D_ACTIVE true
#else
    #define KAPRAYLIB_3D_ACTIVE KAPRAYLIB_3D_ACTIVE_OW
#endif

/**
 * @brief active 2D drawing system
 * 
*/
#ifndef KAPRAYLIB_2D_ACTIVE_OW
    #define KAPRAYLIB_2D_ACTIVE true
#else
    #define KAPRAYLIB_2D_ACTIVE KAPRAYLIB_2D_ACTIVE_OW
#endif
/**
 * @brief active sound system
 * 
*/
#ifndef KAPRAYLIB_SOUND_ACTIVE_OW
    #define KAPRAYLIB_SOUND_ACTIVE true
#else
    #define KAPRAYLIB_SOUND_ACTIVE KAPRAYLIB_SOUND_ACTIVE_OW
#endif

/**
 * @brief The major version of KapRaylib
 * 
 */
#define KAPRAYLIB_VERSION_MAJOR 0
/**
 * @brief The minor version of KapRaylib
 * 
 */
#define KAPRAYLIB_VERSION_MINOR 100
/**
 * @brief The version of KapRaylib
 * 
 */
#define KAPRAYLIB_VERSION "0.100"

#define IS_KAPRAYLIB_VERSION(x, y) (KAPRAYLIB_VERSION_MAJOR != x)? false : (KAPRAYLIB_VERSION_MINOR != y)? false : true
#define IS_MAX_KAPRAYLIB_VERSION(x, y) (KAPRAYLIB_VERSION_MAJOR < x)? true : (KAPRAYLIB_VERSION_MAJOR > x)? false : (KAPRAYLIB_VERSION_MINOR <= y)? true : false
#define IS_MIN_KAPRAYLIB_VERSION(x, y) (KAPRAYLIB_VERSION_MAJOR < x)? false : (KAPRAYLIB_VERSION_MAJOR > x)? true : (KAPRAYLIB_VERSION_MINOR < y)? false : true

#endif /* !KAPRAYLIB_VERSION_HPP_ */
