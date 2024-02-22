/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DrBruisinJuiceIntroEssentialsAudioProcessor::DrBruisinJuiceIntroEssentialsAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

DrBruisinJuiceIntroEssentialsAudioProcessor::~DrBruisinJuiceIntroEssentialsAudioProcessor()
{
}

//==============================================================================
const juce::String DrBruisinJuiceIntroEssentialsAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool DrBruisinJuiceIntroEssentialsAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool DrBruisinJuiceIntroEssentialsAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool DrBruisinJuiceIntroEssentialsAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double DrBruisinJuiceIntroEssentialsAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int DrBruisinJuiceIntroEssentialsAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int DrBruisinJuiceIntroEssentialsAudioProcessor::getCurrentProgram()
{
    return 0;
}

void DrBruisinJuiceIntroEssentialsAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String DrBruisinJuiceIntroEssentialsAudioProcessor::getProgramName (int index)
{
    return {};
}

void DrBruisinJuiceIntroEssentialsAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void DrBruisinJuiceIntroEssentialsAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void DrBruisinJuiceIntroEssentialsAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool DrBruisinJuiceIntroEssentialsAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void DrBruisinJuiceIntroEssentialsAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

 
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());


    //for (int channel = 0; channel < totalNumInputChannels; ++channel)

    //{
    //    auto* channelData = buffer.getWritePointer (channel);

    //    /*for (int sample = 0; sample < buffer.getNumSamples(); ++sample)
    //        channelData[sample] *= 4;*/

    juce::dsp::AudioBlock<float> myBlock(buffer);

    for (int channel = 0; channel < myBlock.getNumChannels(); ++channel)
    {
        auto* channelData = myBlock.getChannelPointer(channel);

        for (int sample = 0; sample <  myBlock.getNumSamples(); ++sample)
            channelData[sample] *= 4;
    }
}

//==============================================================================
bool DrBruisinJuiceIntroEssentialsAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* DrBruisinJuiceIntroEssentialsAudioProcessor::createEditor()
{
    return new DrBruisinJuiceIntroEssentialsAudioProcessorEditor (*this);
}

//==============================================================================
void DrBruisinJuiceIntroEssentialsAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void DrBruisinJuiceIntroEssentialsAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DrBruisinJuiceIntroEssentialsAudioProcessor();
}
