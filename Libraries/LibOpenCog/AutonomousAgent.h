/*
 * Copyright (c) 2025, Ladybird contributors.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Function.h>
#include <AK/String.h>
#include <AK/Vector.h>
#include <LibCore/EventReceiver.h>

namespace OpenCog {

// AutonomousAgent provides an interface for AI-driven browser automation
// and intelligent interaction with web content.
class AutonomousAgent : public Core::EventReceiver {
public:
    enum class AgentState {
        Idle,
        Observing,
        Processing,
        Acting,
        Learning
    };

    virtual ~AutonomousAgent() = default;

    // Initialize the autonomous agent with the browser context
    virtual void initialize();

    // Process web content and extract knowledge
    virtual void observe_web_content(String const& url, String const& content);

    // Make autonomous decisions based on observations
    virtual void process_knowledge();

    // Execute autonomous actions in the browser
    virtual void execute_action(String const& action);

    // Learn from interactions and outcomes
    virtual void learn_from_outcome(String const& outcome);

    // Get current agent state
    AgentState state() const { return m_state; }

    // Set callback for agent actions
    void on_action(Function<void(String const&)> callback) { m_on_action = move(callback); }

protected:
    AutonomousAgent();

    void set_state(AgentState state) { m_state = state; }
    void trigger_action(String const& action);

private:
    AgentState m_state { AgentState::Idle };
    Function<void(String const&)> m_on_action;
    Vector<String> m_knowledge_base;
};

}
