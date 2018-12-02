#include "network_voice_chat.hpp"

int main(int argc, char* argv[])
{
    Network_Voice_Chat voicechat;

    if(argc != 2)
        return EXIT_FAILURE;

    voicechat.setRemote(argv[1]);

    voicechat.start();
    while(getwchar() != L'Q');
    voicechat.stop();

    return EXIT_SUCCESS;
}
