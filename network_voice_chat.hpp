#ifndef NETWORK_VOICE_CHAT_HPP_INCLUDED
#define NETWORK_VOICE_CHAT_HPP_INCLUDED

#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <queue>

class Network_Voice_Chat: private sf::SoundRecorder, private sf::SoundStream, private sf::UdpSocket
{
    std::queue <sf::Packet> m_buffer;
    sf::IpAddress m_ip;
    unsigned short m_port;

    void onSeek(sf::Time timeOffset);
    bool onProcessSamples(const sf::Int16* samples, std::size_t sampleCount);
    bool onGetData(sf::SoundStream::Chunk& data);

public:
    void set_ip_port(sf::IpAddress ip, unsigned short port);
    void bind(unsigned short port);
    void start(unsigned int sampleRate);
    void stop();
};

#endif // NETWORK_VOICE_CHAT_HPP_INCLUDED
