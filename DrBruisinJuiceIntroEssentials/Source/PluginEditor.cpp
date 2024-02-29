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
    setSize (1000, 600);

    addAndMakeVisible(myDial);
    myDial.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    myDial.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 72, 32);
    myDial.setRange(-24.0, 24, 0.1);
    myDial.setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colours::whitesmoke.withAlpha(0.4f));
    myDial.setDoubleClickReturnValue(true, 0.0);

    setResizable(true, true);
    getConstrainer()->setFixedAspectRatio(1.66); //arow is same as dot notation accessor but for a pointer
    setResizeLimits(500, 300, 1000, 600);
}  

DrBruisinJuiceIntroEssentialsAudioProcessorEditor::~DrBruisinJuiceIntroEssentialsAudioProcessorEditor()
{
}

//==============================================================================
void DrBruisinJuiceIntroEssentialsAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId)); //look and feel
    //g.fillAll(juce::Colours::red.darker(0.3).withAlpha(0.2f));
    g.fillAll(juce::Colour::fromFloatRGBA(1.0, 0.1, 0.1, 0.25f));

    g.setColour (juce::Colours::whitesmoke.brighter(0.1).withAlpha(0.5f));// have to appenf f for float for withAlpha
    g.setFont (36.0f);
    g.drawFittedText ("Micaliscious", getLocalBounds(), juce::Justification::centredTop, 1);
}

void DrBruisinJuiceIntroEssentialsAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    auto myLeftMargin = getWidth() * 0.02;
    auto mYTopMargin = getHeight() * 0.04;
    auto myDialSize = getWidth() * 0.20;
    
    myDial.setBounds(myLeftMargin, mYTopMargin, myDialSize, myDialSize);
}
