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
    
    addAndMakeVisible (myDial);
    myDial.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    myDial.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 72, 32);
    myDial.setRange(-24.0, 24, 0.1);
    myDial.setColour(juce::Slider::ColourIds::rotarySliderFillColourId, juce::Colours::whitesmoke.withAlpha(0.4f));
    myDial.setDoubleClickReturnValue(true, 0.0);

    addAndMakeVisible(myButton);
    myButton.setButtonText("myButtony");
    myButton.setClickingTogglesState(true);
    myButton.setColour(juce::TextButton::ColourIds::buttonOnColourId, juce::Colours::lightblue);
    myButton.setColour(juce::TextButton::ColourIds::buttonColourId, juce::Colours::darkgreen);
    myButton.setColour(juce::TextButton::ColourIds::textColourOffId, juce::Colours::pink);
    
    addAndMakeVisible(myToggleButton);

    addAndMakeVisible(myDialLabel);
    myDialLabel.setText("Super Gain", juce::dontSendNotification);
    myDialLabel.attachToComponent(&myDial, false); //  I don't need to set bounds co-ordinates
    myDialLabel.setJustificationType(juce::Justification::centred);



    setResizable(true, true);
    getConstrainer()->setFixedAspectRatio(1.66); //arow is same as dot notation accessor but for a pointer
    setResizeLimits(500, 300, 1000, 600);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(1000, 600);
}  

DrBruisinJuiceIntroEssentialsAudioProcessorEditor::~DrBruisinJuiceIntroEssentialsAudioProcessorEditor()
{
    // if i do stuff with LookAndFeel Class should set to null in this destructor
}


//==============================================================================
void DrBruisinJuiceIntroEssentialsAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    // next three line do all colour the background any one can be used
    //g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    //g.fillAll(juce::Colours::red.darker(0.3).withAlpha(0.2f));
    g.fillAll(juce::Colour::fromFloatRGBA(1.0, 0.1, 0.1, 0.25f));

    g.setColour (juce::Colours::whitesmoke.brighter(0.1).withAlpha(0.5f));// have to append f for float for withAlpha
    g.setFont (36.0f);
    g.drawFittedText ("Micaliscious", getLocalBounds(), juce::Justification::centredTop, 1);
}

void DrBruisinJuiceIntroEssentialsAudioProcessorEditor::resized()
{
    
    //EVERY TIME THE PLUGIN WINDOW IS RESIZED THIS FUNCTION IS CALLED SO I CAN RESIZE AND REPOSITION MY COMPONENTS HERE
    // FYI THE PAINT FUNCTION ALSO GETS CALLED WHEN THE WINDOW IS RESIZED.
    // 
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    
    auto myLeftMargin = getWidth() * 0.02;
    auto myTopMargin = getHeight() * 0.04;
    auto myDialSize = getWidth() * 0.20;
    
    auto myTextBoxW = getWidth() * 0.10;
    auto myTextBoxH = getHeight() * 0.05;
    
    auto myButtonWidth = getWidth() * 0.10;
    auto myButtonHeight = getHeight() * 0.2;

    myDial.setBounds(myLeftMargin, myTopMargin, myDialSize, myDialSize);
    myDial.setTextBoxStyle(juce::Slider::TextBoxBelow, false, myTextBoxW, myTextBoxH);

    myButton.setBounds(myDial.getX() + myDial.getWidth() + myLeftMargin, myTopMargin * 2, myButtonWidth, myButtonHeight);

    myToggleButton.setBounds(myDial.getX() + myDial.getWidth() * 2 + myLeftMargin, myTopMargin * 2, myButtonWidth, myButtonHeight);
    myToggleButton.setButtonText("Toggler");
}

    
