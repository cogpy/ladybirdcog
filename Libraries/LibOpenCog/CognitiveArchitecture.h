/*
 * Copyright (c) 2025, Ladybird contributors.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/String.h>
#include <AK/Vector.h>
#include <LibOpenCog/AutonomousAgent.h>

namespace OpenCog {

// CognitiveArchitecture provides the foundation for OpenCog integration
// This implements the cognitive framework for autonomous browser behavior
class CognitiveArchitecture {
public:
    CognitiveArchitecture();
    ~CognitiveArchitecture() = default;

    // Initialize the cognitive architecture
    void initialize();

    // Get the autonomous agent instance
    AutonomousAgent& agent() { return m_agent; }

    // Process browser events through the cognitive architecture
    void process_browser_event(String const& event_type, String const& event_data);

    // Enable/disable autonomous mode
    void set_autonomous_mode(bool enabled) { m_autonomous_mode_enabled = enabled; }
    bool is_autonomous_mode_enabled() const { return m_autonomous_mode_enabled; }

private:
    AutonomousAgent m_agent;
    bool m_autonomous_mode_enabled { false };
    Vector<String> m_event_history;
};

}
