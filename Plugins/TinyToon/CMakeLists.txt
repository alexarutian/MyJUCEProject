project(TinyToon VERSION 0.0.1)

set (BaseTargetName TinyToon)

juce_add_plugin("${BaseTargetName}"
        # VERSION ...                               # Set this if the plugin version is different to the project version
        # ICON_BIG ...                              # ICON_* arguments specify a path to an image file to use as an icon for the Standalone
        # ICON_SMALL ...
        COMPANY_NAME "MyCompany"
        IS_SYNTH FALSE
        NEEDS_MIDI_INPUT TRUE
        NEEDS_MIDI_OUTPUT FALSE
        IS_MIDI_EFFECT FALSE
        EDITOR_WANTS_KEYBOARD_FOCUS FALSE
        COPY_PLUGIN_AFTER_BUILD TRUE
        PLUGIN_MANUFACTURER_CODE Juce
        PLUGIN_CODE MIpl
        FORMATS AU VST3 Standalone
        PRODUCT_NAME "Tiny Toon Plugin")

target_sources(${BaseTargetName} PRIVATE
        Source/TinyToonProcessor.cpp
        Source/TinyToonEditor.cpp
        )

target_compile_definitions(${BaseTargetName}
        PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0)

juce_add_binary_data(TinyToonBinaryData SOURCES
        Binary/myfont.ttf
)

target_link_libraries(${BaseTargetName} PRIVATE
        shared_plugin_helpers
        juce_audio_utils
        juce_recommended_config_flags
        juce_recommended_lto_flags
        juce_recommended_warning_flags
        TinyToonBinaryData
)


