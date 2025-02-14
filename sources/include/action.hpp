#ifndef _ROGPYTCPP_ACTION_HPP_
#define _ROGPYTCPP_ACTION_HPP_

enum class ActionType {None, Escape, Movement};

struct Action {
    ActionType action_type;
};

struct EscapeAction: Action {
    EscapeAction() {
        action_type = ActionType::Escape;
    }
};

struct MovementAction: Action {
    uint x, y;

    Action(uint x, uint y) {
        this->x = x;
        this->y = y;

        action_type = ActionType::Movement;
    }
};

#endif