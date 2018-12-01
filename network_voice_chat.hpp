#ifndef NETWORK_VOICE_CHAT_HPP_INCLUDED
#define NETWORK_VOICE_CHAT_HPP_INCLUDED

#include <SFML/Audio/SoundStream.hpp>
#include <SFML/Audio/SoundRecorder.hpp>
#include <SFML/Network/Packet.hpp>
#include <SFML/Network/UdpSocket.hpp>

class Network_Voice_Chat: private sf::SoundStream, private sf::SoundRecorder
{
    sf::Packet m_buffer;
    sf::UdpSocket m_socket;
    sf::IpAddress m_ip;
    unsigned short m_port;

    void onSeek(sf::Time timeOffset);
    bool onProcessSamples(const sf::Int16* samples, std::size_t sampleCount);
    bool onGetData(sf::SoundStream::Chunk& data);

public:
    void setProcessingInterval(sf::Time interval);
    void start(sf::IpAddress ip, unsigned int sampleRate = 48000, unsigned short port = 7000);
    void stop();
};

#endif // NETWORK_VOICE_CHAT_HPP_INCLUDED
