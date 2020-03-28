cmake_minimum_required(VERSION 3.4.1)

include_directories(src/main/cpp/include src/main/cpp/source)

aux_source_directory(src/main/cpp/source DIR_SRCS)

# 第三方so库要放在cmakLists.txt文件的根目录下，不然导入会找不到
# 第三方so库如果不放在libs下，虽然再build配置jniLib路径，apk仍然可能不打包相应so库
link_directories(libs/${CMAKE_ANDROID_ARCH_ABI})

add_library(
        fmedia
        SHARED
        ${DIR_SRCS})

target_link_libraries(
        fmedia
        avcodec-58
        avdevice-58
        avfilter-7
        avformat-58
        avutil-56
        postproc-55
        swresample-3
        swscale-5
        log)