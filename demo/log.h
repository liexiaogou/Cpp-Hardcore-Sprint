//#pragma once // 这行非常重要！它告诉编译器：这本说明书每个文件只准看一次，防止看糊涂了
#ifndef _log_h//传统使用方法 可以放在cpp里
#define _log_h
void Inlog();
void Log(const char* message);
struct Player{};

#endif