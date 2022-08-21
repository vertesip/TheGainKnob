/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
APVTStestAudioProcessorEditor::APVTStestAudioProcessorEditor (APVTStestAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalDrag);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 50);

    addAndMakeVisible(gainSlider);

    gainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.apvts, "GAIN", gainSlider);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

APVTStestAudioProcessorEditor::~APVTStestAudioProcessorEditor()
{
}

//==============================================================================
void APVTStestAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);

    g.setColour (juce::Colours::white);
    g.setFont(20.0f);
    g.drawText("The Gain Knob", getLocalBounds(), juce::Justification::centredTop, true);
}

void APVTStestAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getWidth() / 2 - 125, getHeight() / 2 - 75, 250, 150);
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
