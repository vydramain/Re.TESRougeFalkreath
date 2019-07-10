#include <BearLibTerminal.h>
#include <cmath>
#include <iostream>
#include <vector>

int ToPos(float x) { return static_cast<int>(std::round(x)); }

class Controls {
    bool is_jump_ = false;
    bool is_exit_ = false;
    bool is_restart = false;

public:
    bool IsJump() const { return is_jump_; }
    bool IsExit() const { return is_exit_; }
    bool IsRestart() const { return is_restart; }

    void Update() {
        is_jump_ = false;
        is_exit_ = false;
        is_restart = false;
        while (terminal_has_input()) {
            auto key = terminal_read();
            if (key == TK_SPACE) {
                is_jump_ = true;
            } else if (key == TK_CLOSE) {
                is_exit_ = true;
            } else if (key == TK_ENTER) {
                is_restart = true;
            }
        }
    }
};

class World {
public:
    int ground_y;
    float gravity;
    int width;
    float speed;
    bool game_over = false;

    World(int ground_y, float gravity, int width, float speed)
            : ground_y(ground_y), gravity(gravity), width(width), speed(speed) {}
};

class Ground {
    World &world_;

    char symbol = '^';

public:
    explicit Ground(World &world) : world_(world) {}

    void Update() {
        for (int i = 0; i < world_.width; i++) {
            terminal_put(i, world_.ground_y + 1, symbol);
        }
    }
};

class Obstacle {
private:
    void Render() { terminal_put(GetX(), GetY(), '#'); }

public:
    Obstacle(int x, int y) : x(x), y(y) {}

    float x;
    float y;

    void Update() { Render(); }
    int GetX() const { return ToPos(x); }
    int GetY() const { return ToPos(y); }
};

class Player {
    World &world_;
    Controls &controls_;

    float x;
    float y;

    float max_speed_y;
    float max_height;

    float speed_y = 0;

    bool IsFlying() const { return y < world_.ground_y; }

    void Render() { terminal_put(GetX(), GetY(), '@'); }

    void Move() {
        if (controls_.IsJump() && !IsFlying()) {
            speed_y = max_speed_y;
        }
        if (y <= world_.ground_y - max_height) {
            speed_y = 0;
        }
        if (y >= world_.ground_y) {
            y = world_.ground_y;
        }

        y -= speed_y;
        y += world_.gravity;
    }

public:
    Player(World &world, Controls &controls, int x, int y, float max_speed_y,
           float max_height)
            : world_(world), controls_(controls), x(x), y(y),
              max_speed_y(max_speed_y), max_height(max_height) {}
    void Update() {
        Render();
        Move();
    }

    int GetX() const { return ToPos(x); }
    int GetY() const { return ToPos(y); }
};

class ObstacleManager {
    Player &player_;
    World &world_;
    std::vector<Obstacle> obstacles_{
            {30, world_.ground_y}, {55, world_.ground_y}, {75, world_.ground_y}};

    int GenerateNewPlace() const { return world_.width; }

public:
    ObstacleManager(Player &player, World &world)
            : player_(player), world_(world) {}

    void Update() {
        for (auto &o : obstacles_) {
            o.x -= world_.speed;
            if (o.x <= 0) {
                o.x = GenerateNewPlace();
            }

            if (player_.GetX() == o.GetX() && player_.GetY() == o.GetY()) {
                world_.game_over = true;
            }

            o.Update();
        }
    }
};

class Game {
    Controls &controls;
public:
    World world{15, 0.2, 80, 0.2};
    Ground ground{world};
    Player player{world, controls, 1, world.ground_y - 4, world.gravity * 3, 4};
    ObstacleManager obstacles{player, world};

    explicit Game(Controls &controls) : controls(controls) {}
    void Update() {
        player.Update();
        obstacles.Update();
        ground.Update();
    }
};

int main() {
    terminal_open();
    terminal_refresh();

    Controls controls;
    Game* game = new Game{controls};

    // Ждем, пока пользователь не закроет окно
    while (true) {
        terminal_clear();

        controls.Update();
        if (controls.IsExit()) {
            break;
        }
        if (game->world.game_over) {
            terminal_print(1, 1, "Game Over");
            if (controls.IsRestart()) {
                delete game;
                game = new Game{controls};
            }
        } else {
            game->Update();
        }

        terminal_refresh();
    }
    delete game;

    terminal_close();
}