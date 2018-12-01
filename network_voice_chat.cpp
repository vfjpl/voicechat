#include "network_voice_chat.hpp"

void Network_Voice_Chat::onSeek(sf::Time timeOffset) {}

bool Network_Voice_Chat::onProcessSamples(const sf::Int16* samples, std::size_t sampleCount)
{
    m_socket.send(samples, sampleCount*sizeof(sf::Int16), m_ip, m_port);
    return true;
}

bool Network_Voice_Chat::onGetData(sf::SoundStream::Chunk& data)
{
    sf::IpAddress ip;
    unsigned short port;

    m_socket.receive(m_buffer, ip, port);
    m_ip = ip;
    m_port = port;

    data.samples = (sf::Int16*)m_buffer.getData();
    data.sampleCount = m_buffer.getDataSize()/sizeof(sf::Int16);
    return true;
}

void Network_Voice_Chat::setProcessingInterval(sf::Time interval)
{
    sf::SoundRecorder::setProcessingInterval(interval);
}

void Network_Voice_Chat::start(sf::IpAddress ip, unsigned int sampleRate, unsigned short port)
{
    m_socket.bind(port);
    sf::SoundStream::initialize(sf::SoundRecorder::getChannelCount(), sampleRate);
    m_ip = ip;
    m_port = port;

    sf::SoundRecorder::start(sampleRate);
    sf::SoundStream::play();
}

void Network_Voice_Chat::stop()
{
    sf::SoundStream::stop();
    sf::SoundRecorder::stop();
}
