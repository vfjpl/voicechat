#include "network_voice_chat.hpp"

int main(int argc, char* argv[])
{
    Network_Voice_Chat voicechat;

    if(argc != 2)
        return EXIT_FAILURE;

    voicechat.start(argv[1]);
    while(getwchar() != L'Q');
    voicechat.stop();

    return EXIT_SUCCESS;
}
