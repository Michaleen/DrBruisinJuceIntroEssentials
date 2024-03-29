/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class DrBruisinJuiceIntroEssentialsAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    DrBruisinJuiceIntroEssentialsAudioProcessorEditor (DrBruisinJuiceIntroEssentialsAudioProcessor&);
    ~DrBruisinJuiceIntroEssentialsAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DrBruisinJuiceIntroEssentialsAudioProcessor& audioProcessor;

    juce::Slider myDial;
    juce::TextButton myButton;
    juce::ToggleButton myToggleButton;
    juce::Label myDialLabel;

    void initMyDial();
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DrBruisinJuiceIntroEssentialsAudioProcessorEditor)
};
