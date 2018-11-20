#include "network_voice_chat.hpp"

int main(int argc, char* argv[])
{
    Network_Voice_Chat voicechat;
    sf::Clock clock;

    if(argc != 2)
        return EXIT_FAILURE;

    voicechat.bind(7000);
    voicechat.set_ip_port(argv[1], 7000);

    voicechat.start(48000);
    while(true)
        sf::sleep(clock.restart());
    voicechat.stop();

    return EXIT_SUCCESS;
}
