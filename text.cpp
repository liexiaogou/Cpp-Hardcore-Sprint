#include<iostream>
int main(){
    int i=0;
    bool conmd=true;

    for(;conmd;){
        std::cout<<"输出第"<<i<<"次"<<std::endl;
        i++;
        if(!(i<10)){
         conmd=false;
        }
        
    }
}