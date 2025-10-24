set(SOURCES
    AutonomousAgent.cpp
    CognitiveArchitecture.cpp
)

ladybird_lib(LibOpenCog opencog)
target_link_libraries(LibOpenCog PRIVATE LibCore)
