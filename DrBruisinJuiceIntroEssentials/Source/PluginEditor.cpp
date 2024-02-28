/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.
//C:\Users\Mic Dev\JUCE\extras\AudioPluginHost\Builds\VisualStudio2019\x64\Debug\App\AudioPluginHost.exe
  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DrBruisinJuiceIntroEssentialsAudioProcessorEditor::DrBruisinJuiceIntroEssentialsAudioProcessorEditor (DrBruisinJuiceIntroEssentialsAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

DrBruisinJuiceIntroEssentialsAudioProcessorEditor::~DrBruisinJuiceIntroEssentialsAudioProcessorEditor()
{
}

//==============================================================================
void DrBruisinJuiceIntroEssentialsAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Micaliscious", getLocalBounds(), juce::Justification::centred, 1);
}

void DrBruisinJuiceIntroEssentialsAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
