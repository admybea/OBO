#include<stdio.h>
#include<curl/curl.h>

int main()
{
    CURL*curl=NULL;
    CURLcode cc;
    //初始化一个curl句柄
    curl=curl_easy_init();
    if(curl==NULL)
    {
        perror("init curl error\n");
        return  -1;
    }


    //给curl设置一些参数
    cc=curl_easy_setopt(curl,CURLOPT_URL,"http://www.baidu.com");
    if(cc!=CURLE_OK)
    {
        perror("set opt error");
        return  -1;
    }
    //发送curl请求
    cc=curl_easy_perform(curl);
    if(cc!=CURLE_OK)
    {
        perror("set opt error");
        return  -1;
    }
    //释放句柄
    curl_easy_cleanup(curl);
    return 0;
}
