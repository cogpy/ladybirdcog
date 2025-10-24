/*
 * Copyright (c) 2025, Ladybird contributors.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibOpenCog/AutonomousAgent.h>
#include <LibOpenCog/CognitiveArchitecture.h>
#include <LibTest/TestCase.h>

TEST_CASE(autonomous_agent_initialization)
{
    OpenCog::AutonomousAgent agent;
    agent.initialize();
    EXPECT_EQ(agent.state(), OpenCog::AutonomousAgent::AgentState::Idle);
}

TEST_CASE(autonomous_agent_state_transitions)
{
    OpenCog::AutonomousAgent agent;
    agent.initialize();
    
    // Test observation
    agent.observe_web_content("https://example.com"_string, "<html></html>"_string);
    EXPECT_EQ(agent.state(), OpenCog::AutonomousAgent::AgentState::Idle);
    
    // Test processing
    agent.process_knowledge();
    EXPECT_EQ(agent.state(), OpenCog::AutonomousAgent::AgentState::Idle);
    
    // Test action execution
    agent.execute_action("click"_string);
    EXPECT_EQ(agent.state(), OpenCog::AutonomousAgent::AgentState::Idle);
    
    // Test learning
    agent.learn_from_outcome("success"_string);
    EXPECT_EQ(agent.state(), OpenCog::AutonomousAgent::AgentState::Idle);
}

TEST_CASE(autonomous_agent_action_callback)
{
    OpenCog::AutonomousAgent agent;
    agent.initialize();
    
    String received_action;
    agent.on_action([&](String const& action) {
        received_action = action;
    });
    
    agent.execute_action("test_action"_string);
    EXPECT_EQ(received_action, "test_action"_string);
}

TEST_CASE(cognitive_architecture_initialization)
{
    OpenCog::CognitiveArchitecture architecture;
    architecture.initialize();
    
    EXPECT_EQ(architecture.is_autonomous_mode_enabled(), false);
    EXPECT_EQ(architecture.agent().state(), OpenCog::AutonomousAgent::AgentState::Idle);
}

TEST_CASE(cognitive_architecture_autonomous_mode)
{
    OpenCog::CognitiveArchitecture architecture;
    architecture.initialize();
    
    // Enable autonomous mode
    architecture.set_autonomous_mode(true);
    EXPECT_EQ(architecture.is_autonomous_mode_enabled(), true);
    
    // Disable autonomous mode
    architecture.set_autonomous_mode(false);
    EXPECT_EQ(architecture.is_autonomous_mode_enabled(), false);
}

TEST_CASE(cognitive_architecture_event_processing)
{
    OpenCog::CognitiveArchitecture architecture;
    architecture.initialize();
    
    // Process events without autonomous mode
    architecture.process_browser_event("page_load"_string, "https://example.com"_string);
    
    // Enable autonomous mode and process events
    architecture.set_autonomous_mode(true);
    architecture.process_browser_event("click"_string, "button_id"_string);
    
    // Agent should remain in idle state after processing
    EXPECT_EQ(architecture.agent().state(), OpenCog::AutonomousAgent::AgentState::Idle);
}
