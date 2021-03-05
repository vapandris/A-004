#pragma once

typedef struct View_GameView View_GameView;

View_GameView*  View_GameView_Create();
void            View_GameView_Destroy(const View_GameView* self);

void    View_GameView_Start(View_GameView* self);