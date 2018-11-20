#include "network_voice_chat.hpp"

void Network_Voice_Chat::onSeek(sf::Time timeOffset) {}

bool Network_Voice_Chat::onProcessSamples(const sf::Int16* samples, std::size_t sampleCount)
{
    send(samples, sampleCount*2, m_ip, m_port);
    return true;
}

bool Network_Voice_Chat::onGetData(sf::SoundStream::Chunk& data)
{
    sf::IpAddress ip;
    unsigned short port;

    m_buffer.pop();
    m_buffer.emplace();
    receive(m_buffer.back(), ip, port);
    data.samples = (const sf::Int16*)m_buffer.front().getData();
    data.sampleCount = m_buffer.front().getDataSize()/2;
    return true;
}

void Network_Voice_Chat::set_ip_port(sf::IpAddress ip, unsigned short port)
{
    m_ip = ip;
    m_port = port;
}

void Network_Voice_Chat::bind(unsigned short port)
{
    sf::UdpSocket::bind(port);
}

void Network_Voice_Chat::setProcessingInterval(sf::Time interval)
{
    sf::SoundRecorder::setProcessingInterval(interval);
}

void Network_Voice_Chat::start(unsigned int sampleRate)
{
    sf::SoundStream::initialize(sf::SoundRecorder::getChannelCount(), sampleRate);
    m_buffer.emplace();
    sf::SoundRecorder::start(sampleRate);
    sf::SoundStream::play();
}

void Network_Voice_Chat::stop()
{
    sf::SoundStream::stop();
    sf::SoundRecorder::stop();
    while(!m_buffer.empty())
        m_buffer.pop();
}
