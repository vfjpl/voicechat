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

    bool onProcessSamples(const sf::Int16* samples, std::size_t sampleCount) final;
    bool onGetData(sf::SoundStream::Chunk& data) final;
    void onSeek(sf::Time timeOffset) final;

public:
    void setProcessingInterval(sf::Time interval);
    void setRemote(sf::IpAddress ip, unsigned short port = 7000);
    void start(unsigned int sampleRate = 48000);
    void stop();
};

#endif // NETWORK_VOICE_CHAT_HPP_INCLUDED
