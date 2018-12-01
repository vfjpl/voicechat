#include "network_voice_chat.hpp"

int main(int argc, char* argv[])
{
    Network_Voice_Chat voicechat;

    if(argc != 2)
        return EXIT_FAILURE;

    voicechat.set_ip_port(argv[1], 7000);
    voicechat.bind(7000);

    voicechat.start();
    while(getwchar() != L'Q');
    voicechat.stop();

    voicechat.unbind();

    return EXIT_SUCCESS;
}
