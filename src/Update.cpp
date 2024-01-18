//
// Created by John on 17/1/2024 AD.
//


#include "../header/Engine.h"

void Engine::Update() {
//    if(timeSinceLastMove.asSeconds() >= seconds(1.f/float(speed)).asSeconds()){
    if (timeSinceLastMove.asSeconds() >= seconds(1.f / float(speed)).asSeconds()) {
        Vector2f thisSectionPosition = snake[0].getPosition();
        Vector2f lastSectionPosition = thisSectionPosition;

        if (!directionQueue.empty()){
            switch (snakeDirection) {
                case Direction::UP:
                    if(directionQueue.front() != Direction::DOWN){
                        snakeDirection = directionQueue.front();
                    }
                    break;
                case Direction::DOWN:
                    if(directionQueue.front() != Direction::UP){
                        snakeDirection = directionQueue.front();
                    }
                    break;
                case Direction::LEFT:
                    if(directionQueue.front() != Direction::RIGHT){
                        snakeDirection = directionQueue.front();
                    }
                    break;
                case Direction::RIGHT:
                    if(directionQueue.front() != Direction::LEFT){
                        snakeDirection = directionQueue.front();
                    }
                    break;

            }
            directionQueue.pop_front();
        }

        score += snake.size() + (fruitsEatenTotal + 1);
        scoreText.setString("Score : " + to_string(score));
        FloatRect scoreTextBounds = scoreText.getGlobalBounds();
        scoreText.setPosition(Vector2f(resolution.x - scoreTextBounds.width - 15, -3));

        if(sectionsToAdd){
            AddSnakeSection();
            sectionsToAdd--;
        }

        switch (snakeDirection) {
            case Direction::RIGHT:
                snake[0].setPosition(Vector2f(thisSectionPosition.x + 20, thisSectionPosition.y));
                break;
            case Direction::DOWN:
                snake[0].setPosition(Vector2f(thisSectionPosition.x, thisSectionPosition.y + 20));
                break;
            case Direction::LEFT:
                snake[0].setPosition(Vector2f(thisSectionPosition.x - 20, thisSectionPosition.y));
                break;
            case Direction::UP:
                snake[0].setPosition(Vector2f(thisSectionPosition.x, thisSectionPosition.y - 20));
                break;
        }

        for (int s = 1; s < snake.size(); s++) {
            thisSectionPosition = snake[s].getPosition();
            snake[s].setPosition(lastSectionPosition);
            lastSectionPosition = thisSectionPosition;
        }

        for(auto & s : snake){
            s.Update();
        }

        if(snake[0].getShape().getGlobalBounds().intersects(fruit.getSprite().getGlobalBounds())) {
            fruitsEatenInThisLevel++;
            fruitsEatenTotal++;
            fruitEatenText.setString("Fruit : " + to_string(fruitsEatenInThisLevel));
            FloatRect currentLevelTextBounds = currentLevelText.getGlobalBounds();
            fruitEatenText.setPosition(Vector2f(currentLevelTextBounds.left + currentLevelTextBounds.width + 20, -3));

            bool beginningNewLevel = false;
            if(fruitsEatenInThisLevel >= 10){
                if(currentLevel < maxLevels){
                    beginningNewLevel = true;
                    BeginNextLevel();
                }
            }

            if(!beginningNewLevel){
                sectionsToAdd +=4;
                speed++;
                MoveFruit();
            }
        }

        for (int s = 1; s < snake.size();s++){
            if(snake[0].getShape().getGlobalBounds().intersects(snake[s].getShape().getGlobalBounds())){
                currentGameState = GameState::GAMEOVER;
            }
        }

        for (auto & w : wallSections) {
            if (snake[0].getShape().getGlobalBounds().intersects(w.getShape().getGlobalBounds())) {
                // Game Over
                currentGameState = GameState::GAMEOVER;
            }
        }

        timeSinceLastMove = Time::Zero;
    }
}