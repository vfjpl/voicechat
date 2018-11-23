#include "network_voice_chat.hpp"

void Network_Voice_Chat::onSeek(sf::Time timeOffset) {}

bool Network_Voice_Chat::onProcessSamples(const sf::Int16* samples, std::size_t sampleCount)
{
    m_socket.send(samples, sampleCount*2, m_ip, m_port);
    return true;
}

bool Network_Voice_Chat::onGetData(sf::SoundStream::Chunk& data)
{
    sf::IpAddress ip;
    unsigned short port;

    m_socket.receive(m_buffer, ip, port);
    m_ip = ip;
    m_port = port;

    data.samples = (const sf::Int16*)m_buffer.getData();
    data.sampleCount = m_buffer.getDataSize()/2;
    return true;
}

void Network_Voice_Chat::set_ip_port(sf::IpAddress ip, unsigned short port)
{
    m_ip = ip;
    m_port = port;
}

void Network_Voice_Chat::bind(unsigned short port)
{
    m_socket.bind(port);
}

void Network_Voice_Chat::unbind()
{
    m_socket.unbind();
}

void Network_Voice_Chat::setProcessingInterval(sf::Time interval)
{
    sf::SoundRecorder::setProcessingInterval(interval);
}

void Network_Voice_Chat::start(unsigned int sampleRate)
{
    sf::SoundStream::initialize(sf::SoundRecorder::getChannelCount(), sampleRate);
    sf::SoundRecorder::start(sampleRate);
    sf::SoundStream::play();
}

void Network_Voice_Chat::stop()
{
    sf::SoundStream::stop();
    sf::SoundRecorder::stop();
    m_buffer.clear();
}
