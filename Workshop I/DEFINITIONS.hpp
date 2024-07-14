
#pragma once

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#define SPLASH_STATE_SHOW_TIME 3.0

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/Splash Background Hi.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/Background.jpg"
#define GAME_BACKGROUND_FILEPATH "Resources/res/Background.jpg"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/Background.jpg"

#define GAME_TITLE_FILEPATH "Resources/res/LogoA.png"
#define LEVELONE_BUTTON_FILEPATH "Resources/res/LevelOneButton.png"
#define LEVELTWO_BUTTON_FILEPATH "Resources/res/LevelTwoButton.png"

#define HTP_BACKGROUND_FILEPATH "Resources/res/HOW TO PLAY.png"
#define HTP_BUTTON_FILEPATH "Resources/res/HTPButton.png"
#define BTM_BUTTON_FILEPATH "Resources/res/BTMButton.png"

#define SHIRT_FILEPATH "Resources/res/Shirt.png"
#define WRAPPER_FILEPATH "Resources/res/Wrapper.png"
#define PIZZA_FILEPATH "Resources/res/Pizza.png"

#define ROACH_FRAME_1_FILEPATH "Resources/res/cockroacha.png"
#define ROACH_FRAME_2_FILEPATH "Resources/res/cockroachb.png"
#define ROACH_FRAME_3_FILEPATH "Resources/res/cockroachc.png"
#define ROACH_FRAME_4_FILEPATH "Resources/res/cockroachd.png"

#define MOUSE_FRAME_1_FILEPATH "Resources/res/Mousea.png"
#define MOUSE_FRAME_2_FILEPATH "Resources/res/Mouseb.png"
#define MOUSE_FRAME_3_FILEPATH "Resources/res/Mousec.png"
#define MOUSE_FRAME_4_FILEPATH "Resources/res/Moused.png"

#define SCORING_PIZZA_FILEPATH "Resources/res/InvisibleScoring.png"

#define ROACH_FONT_FILEPATH "Resources/fonts/Gameplay.ttf"

#define BACK_BUTTON_FILEPATH "Resources/res/BackButton.png"

#define GAME_OVER_TITLE_FILEPATH "Resources/res/GameOver.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/GameOverBody.png"
#define MENU_BUTTON_FILEPATH "Resources/res/MenuButton.png"
#define REPLAY_BUTTON_FILEPATH "Resources/res/ReplayButton.png"

#define HIT_SOUND_FILEPATH "Resources/audio/hit.wav"
#define EAT_SOUND_FILEPATH "Resources/audio/eat.wav"
#define BGM_SOUND_FILEPATH "Resources/audio/antifragile.wav"


#define SHIRT_MOVEMENT_SPEED 300.0f
#define SHIRT_SPAWN_FREQUENCY 3.0f
#define SHIRT_MOVEMENT_SPEED_TWO 350.0f
#define SHIRT_SPAWN_FREQUENCY_TWO 2.0f

#define WRAPPER_MOVEMENT_SPEED 300.0f
#define WRAPPER_SPAWN_FREQUENCY 3.0f
#define WRAPPER_MOVEMENT_SPEED_TWO 350.0f
#define WRAPPER_SPAWN_FREQUENCY_TWO 2.0f

#define PIZZA_MOVEMENT_SPEED 300.0f
#define PIZZA_SPAWN_FREQUENCY 3.0f
#define PIZZA_MOVEMENT_SPEED_TWO 350.0f
#define PIZZA_SPAWN_FREQUENCY_TWO 2.0f

#define ROACH_ANIMATION_DURATION 0.8f

#define ROACH_STATE_STILL 1
#define ROACH_STATE_FALLING 2
#define ROACH_STATE_WALKING 3

#define MOUSE_ANIMATION_DURATION 0.8f

#define MOUSE_STATE_STILL 1
#define MOUSE_STATE_WALKING 2
#define MOUSE_STATE_FALLING 3


#define GRAVITY 350.0f

#define WALKING_SPEED 350.0f
#define WALKING_SPEED_ONE 370.0f

#define WALKING_DURATION 0.30f
#define WALKING_DURATION_ONE 0.25f

#define ROTATION_SPEED 100.0f

enum GameStates
{
	eReady,
	ePlaying,
	eGameOver
};

#define FLASH_SPEED 1500.0f

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f