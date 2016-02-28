g_Item = {
  sprite = 0,
  state = 0,
  direction = 0
}

g_Enemies = {}
for i = 0, 12 do
  g_Enemies[i]  = {
      sprite = 0,
      state = 0,
      delay = 0,
      time = 0,
      bottomY = 0,
      topY = 0,
      topDelay = 0,
      speedUp = 0,
      speedDown = 0,
      waitAtTop = 0,
      temp = 0
  }
end

g_Level = {
  background = 0,
  foreground = 0,
  pause = 0,
  play = 0,
  pauseButton = 0,

  overlay1 = 0,
  overlay2 = 0,
  overlay3 = 0,

  TimerIncrement = 0,
  Timer = 0,
  Limit = 0,
  TimeLimit = 0,
  EnemiesUp = 0,
  lastTime = 0,

  miss = 0,

  scoreText = 0,
  timerText = 0,
  miscText = 0,
  continueText = 0,
  mainMenuText = 0,

  score = 0,

  targetHit = 0,
  targetAccuracy = 0,

  hitAttempts = 0,
  enemiesMissed = 0,
  missTimer = 0,
  enemiesHit = 0
}

g_Clouds = {}
for i = 0, 3 do
  g_Clouds [ i ] = 0
end
g_MoleImages = {}
for i = 0, 11 do
  g_MoleImages [ i ] = 0
end
g_Text = {}
for i = 0, 5 do
  g_Text [ i ] = 0
end

g_LastPopup = 0
g_Overlay = 0

g_StatsText = {}
for i = 0, 12 do
  g_StatsText [ i ] = 0
end

eDisplayFadeIn = 0
eDisplayMainMenu = 1
eDisplayStartGame = 2
eLoadLevel = 3
ePlayLevel = 4
ePause = 5
eLevelWon = 6
eLevelLost = 7
g_State = 0
g_PreviousState = 0
g_PauseState = 0
g_GameOverState = 0
g_Alarm = 0

function Setup()
  SetCurrentDir("media")
  
  SetupMainMenu ( )
end

function Update()
    if g_State == 0 then
      DisplayFadeIn ( )
    elseif g_State == 1 then
      DisplayMainContents ( )
    elseif g_State == 2 then
      DisplayStartGame ( )
    elseif g_State == 3 then
      LoadLevel ( 0 )
    elseif g_State == 4 then
      PlayLevel ( )
    elseif g_State == 5 then
      HandlePause ( )
    elseif g_State == 6 then
      HandleWin ( )
    elseif g_State == 7 then
      HandleLose ( )
    end

    Sync ( )  
end

function HandleLose ( )
        EndLevel ( 2 )
end

function HandleWin ( )
        EndLevel ( 1 )
end

function EndLevel ( mode )
        if g_GameOverState == 0 then
                count = 0

                SetSpritePosition ( g_Level.pauseButton, -100.0, -100.0 )

                for i = 1, 9 do
                        HandleEnemyDown ( i )

                        if ( g_Enemies [ i ].state == 0 ) then
                                count = count + 1
                        end
                end

                if ( GetSpriteColorAlpha ( g_Item.sprite ) > 12 ) then
                        SetSpriteColorAlpha ( g_Item.sprite, GetSpriteColorAlpha ( g_Item.sprite ) - 12 )
                else
                        count = count + 1
                end

                if ( count == 10 ) then
                        g_GameOverState = 1
                end
        end

        if g_GameOverState == 1 then
                SetTextVisible ( g_Level.scoreText, 0 )
                SetTextVisible ( g_LevelTtimerText, 0 )

                percent = math.floor(( g_Level.enemiesHit * 100.0 ) / g_Level.hitAttempts)

                y = 180

                for i = 1, 12 do
                        g_StatsText [ i ] = CreateText ( "" )

                        SetTextPosition ( g_StatsText [ i ], -100.0, -100.0 )
                        SetTextColor    ( g_StatsText [ i ], 255, 255, 255, 0 )
                        SetTextDepth    ( g_StatsText [ i ], 0 )

                        if ( i == 1 ) then
                                SetTextPosition ( g_StatsText [ i ], 55.0, 50.0 )
                                SetTextSize     ( g_StatsText [ i ], 24.0 )
                        elseif ( i == 10 ) then
                                SetTextPosition ( g_StatsText [ i ], 23.0, 395.0 )
                                SetTextSize     ( g_StatsText [ i ], 18.0 )
                        else
                                SetTextSize     ( g_StatsText [ i ], 12.0 )
                        end
                end

                if ( mode == 1 ) then SetTextString ( g_StatsText [ 1 ], "WELL DONE" ) end
                if ( mode == 2 ) then SetTextString ( g_StatsText [ 1 ], "GAME OVER" ) end

                SetTextPosition ( g_StatsText [ 1 ], 55.0, 50.0 )

                text = "SCORE:_____________" .. string.format ("%d", g_Level.score )
                SetTextString ( g_StatsText [ 2 ], text )
                SetTextPosition ( g_StatsText [ 2 ], 10.0, 180.0 )

                text = "CRITTERS_UP:_______" .. string.format ("%d", g_Level.EnemiesUp )
                SetTextString ( g_StatsText [ 3 ], text )
                SetTextPosition ( g_StatsText [ 3 ], 10.0, 200.0 )

                text = "HIT_ATTEMPTS:______" .. string.format ("%d", g_Level.hitAttempts )
                SetTextString ( g_StatsText [ 4 ], text )
                SetTextPosition ( g_StatsText [ 4 ], 10.0, 220.0 )

                text = "CRITTERS_HIT:______" .. string.format ("%d", g_Level.enemiesHit )
                SetTextString ( g_StatsText [ 5 ], text )
                SetTextPosition ( g_StatsText [ 5 ], 10.0, 240.0 )

                text = "CRITTERS_MISSED:___" .. string.format ("%d", g_Level.enemiesMissed )
                SetTextString ( g_StatsText [ 6 ], text )
                SetTextPosition ( g_StatsText [ 6 ], 10.0, 260.0 )

                text = "ACCURACY:__________" .. string.format ("%d", percent ) .. "%"
                SetTextString ( g_StatsText [ 7 ], text )
                SetTextPosition ( g_StatsText [ 7 ], 10.0, 280.0 )

                text = "TARGET_HIT:________" .. string.format ("%d", g_Level.targetHit )
                SetTextString ( g_StatsText [ 8 ], text )
                SetTextPosition ( g_StatsText [ 8 ], 10.0, 300.0 )

                text = "TARGET_ACCURACY:___" .. string.format ("%d", g_Level.targetAccuracy ) .. "%"
                SetTextString ( g_StatsText [ 9 ], text )
                SetTextPosition ( g_StatsText [ 9 ], 10.0, 320.0 )

                SetTextString ( g_StatsText [ 10 ], "TAP TO CONTINUE" )
                SetTextPosition ( g_StatsText [ 10 ], 23.0, 395.0 )

                g_GameOverState = 2
        end

        if g_GameOverState == 2 then
                for i = 1, 11 do
                        alpha = GetTextColorAlpha ( g_StatsText [ i ] )

                        if ( alpha < 255 - 4 ) then
                                alpha = alpha + 4
                        end

                        SetTextColorAlpha ( g_StatsText [ i ], alpha )
                end

                if GetPointerPressed ( ) == 1 then
                        UnloadLevel ( )

                        for i = 1, 5 do
                                SetTextVisible ( g_Text [ i ], 1 )
                        end

                        g_Item.state = 0
                        SetSpritePosition ( g_Item.sprite, -150, 15 )

                        g_State = eDisplayFadeIn
                end
        end
end

function HandlePause ( )
        if ( g_PauseState == 0 ) then
                SetTextPosition ( g_Level.continueText, 65.0, 200.0 )
                SetTextPosition ( g_Level.mainMenuText, 55.0, 280.0 )

                if ( GetTextColorAlpha ( g_Level.continueText ) < 255 - 4 ) then
                        SetTextColorAlpha ( g_Level.continueText, GetTextColorAlpha ( g_Level.continueText ) + 4 )
                        SetTextColorAlpha ( g_Level.mainMenuText, GetTextColorAlpha ( g_Level.mainMenuText ) + 4 )
                end

                if GetPointerPressed ( ) == 1 then
                        x = GetPointerX ( )
                        y = GetPointerY ( )

                        -- pause / play button
                        if ( x >= 0 and x <= 40 and y >= 0 and y <= 40 ) then
                                g_PauseState = 1
                        end

                        -- continue button
                        if ( x >= 50 and x <= 270 and y >= 185 and y <= 240 ) then
                                g_PauseState = 1
                        end

                        -- main menu button
                        if ( x >= 40 and x <= 280 and y >= 265 and y <= 320 ) then
                                g_PauseState = 2
                        end
                end
        else
                if ( GetTextColorAlpha ( g_Level.continueText ) > 4 ) then
                        SetTextColorAlpha ( g_Level.continueText, GetTextColorAlpha ( g_Level.continueText ) - 4 )
                        SetTextColorAlpha ( g_Level.mainMenuText, GetTextColorAlpha ( g_Level.mainMenuText ) - 4 )
                else
                        SetTextColorAlpha ( g_Level.continueText, 0 )
                        SetTextColorAlpha ( g_Level.mainMenuText, 0 )

                        SetTextPosition ( g_Level.continueText, -200.0, -200.0 )
                        SetTextPosition ( g_Level.mainMenuText, -200.0, -200.0 )

                        SetSpriteImage ( g_Level.pauseButton, g_Level.pause )

                        if ( g_PauseState == 1 ) then
                                g_State = g_PreviousState
                        else
                                alpha = GetSpriteColorAlpha ( g_Overlay )

                                if ( alpha < 255 - 4 ) then
                                        alpha = alpha + 4
                                        SetSpriteColor ( g_Overlay, 255, 255, 255, alpha )
                                else
                                        UnloadLevel ( )

                                        for i = 1, 5 do
                                                SetTextVisible ( g_Text [ i ], 1 )
                                        end

                                        g_Item.state = 0
                                        SetSpritePosition ( g_Item.sprite, -150, 15 )

                                        g_State = eDisplayFadeIn
                                end
                        end
                end
        end
end

function UnloadLevel ( )
        DeleteSprite ( g_Level.background )
        DeleteSprite ( g_Level.foreground )
        DeleteSprite ( g_Level.pauseButton )

        for i = 1, 9 do
                DeleteSprite ( g_Enemies [ i ].sprite )
        end

        DeleteSprite ( g_Level.overlay1 )
        DeleteSprite ( g_Level.overlay2 )
        DeleteSprite ( g_Level.overlay3 )

        DeleteSprite ( g_Level.miss )

        DeleteText ( g_Level.scoreText )
        DeleteText ( g_LevelTtimerText )
        DeleteText ( g_Level.miscText )
        DeleteText ( g_Level.continueText )
        DeleteText ( g_Level.mainMenuText )

        for i = 1, 12 do
                DeleteText ( g_StatsText [ i ] )
        end
end

function PlayLevel ( )
        UpdateItems   ( )
        UpdateEnemiesInGame ( )
        CheckForPause ( )
        CheckForInput ( )
        UpdateInfo ( )
        UpdateTime ( )
end

function UpdateTime ( )
        if ( GetSeconds ( ) > g_Level.lastTime ) then
                if ( g_Level.TimeLimit > 0 ) then
                  g_Level.TimeLimit = g_Level.TimeLimit - 1
                end

                g_Level.lastTime = GetSeconds ( )
        end

        if ( g_Level.TimeLimit < 5 ) then
                if g_Alarm == 0 then
                        PlaySound ( 8, 100, 1 )
                        g_Alarm = 1
                end
        else
                StopSound ( 8 )
        end

        if ( g_Level.TimeLimit == 0 ) then
                g_Alarm = 0
                StopSound ( 8 )

                fAccuracy = ( g_Level.enemiesHit /  g_Level.hitAttempts ) * 100.0

                for i = 1, 9 do
                        StopSprite ( g_Enemies [ i ].sprite )
                end

                if ( g_Level.enemiesHit >= g_Level.targetHit and fAccuracy >= g_Level.targetAccuracy ) then
                        g_State = eLevelWon
                else
                        g_State = eLevelLost
                end

                g_GameOverState = 0

                SetSpritePosition ( g_Level.miss, -100.0, -100.0 )
        end
end

function UpdateInfo ( )
        SetTextString ( g_Level.scoreText, string.format("%d", g_Level.score ) )
        SetTextString ( g_LevelTtimerText, string.format ("%d", g_Level.TimeLimit ) )
end

function CheckForInput ( )
        if ( GetSpriteX ( g_Level.miss ) > 0 ) then
                if ( GetSpriteColorAlpha ( g_Level.miss ) > 2 ) then
                        SetSpriteColor ( g_Level.miss, 255, 255, 255, GetSpriteColorAlpha ( g_Level.miss ) - 2 )
                        SetSpriteY     ( g_Level.miss, GetSpriteY ( g_Level.miss ) + 1 )
                end

                g_Level.missTimer = g_Level.missTimer + 1

                if ( g_Level.missTimer > 120 ) then
                        SetSpritePosition ( g_Level.miss, -100.0, -100.0 )
                end
        end

        if GetPointerPressed ( ) == 1 then
                g_Level.hitAttempts = g_Level.hitAttempts + 1

                hitOne = 0

                for i = 1, 9 do
                        if ( g_Enemies [ i ].state == 1 or g_Enemies [ i ].state == 2 or g_Enemies [ i ].state == 3 ) then

                                if GetSpriteColorAlpha ( g_Enemies [ i ].sprite ) < 20 then
                                        break
                                end

                                if ( GetSpriteHitTest ( g_Enemies [ i ].sprite, GetPointerX ( ), GetPointerY ( ) ) == 1 ) then
                                        PlaySound ( Random ( 1, 5 ) )

                                        StopSprite ( g_Enemies [ i ].sprite )
                                        g_Enemies [ i ].temp = 0
                                        g_Enemies [ i ].state = 4

                                        g_Level.enemiesHit = g_Level.enemiesHit + 1
                                        g_Level.score = g_Level.score + 5

                                        hitOne = 1
                                end
                        end
                end

                if hitOne == 0 then
                        if GetPointerY ( ) > 100 then
                                -- add to enemies missed
                                g_Level.enemiesMissed = g_Level.enemiesMissed + 1

                                PlaySound ( 7 )

                                -- reduce time if it's possible
                                if ( g_Level.TimeLimit > 5 ) then
                                        g_Level.TimeLimit = g_Level.TimeLimit - 5
                                end

                                -- show our miss sprite
                                SetSpriteColor    ( g_Level.miss, 255, 255, 255, 255 )
                                SetSpritePosition ( g_Level.miss, GetPointerX ( ) - 16.0, GetPointerY ( ) - 16.0 )

                                -- reset miss timer
                                g_Level.missTimer = 0
                        end
                end
        end
end

function CheckForPause ( )
        if GetPointerPressed ( ) == 1 then
                x = GetPointerX ( )
                y = GetPointerY ( )

                if x >= 0 and x <= 60 and y >= 0 and y <= 50 then
                        for i = 1, 9 do
                                StopSprite ( g_Enemies [ i ].sprite )
                        end

                        StopSprite ( g_Item.sprite )

                        SetSpriteImage ( g_Level.pauseButton, g_Level.play )

                        g_PreviousState = g_State
                        g_PauseState = 0
                        g_State = ePause
                end
        end
end

function UpdateEnemiesInGame ( )

        g_Level.Timer = g_Level.Timer + 1

        if ( g_Level.Timer > g_Level.Limit and g_Level.TimeLimit > 2 ) then

                -- set up a random list
                pick = {}

                start = Random ( 1, 9 )

                for i = 1, 9 do
                        pick [ i ] = start

                        start = start + 1

                        if start > 9 then
                                start = 1
                        end
                end

                for i = 1, 9 do
                        if ( g_Enemies [ pick [ i ] ].state == 0 and pick [ i ] ~= g_LastPopup ) then

                                index = pick [ i ]

                                g_Enemies [ index ].state    = 1
                                g_Enemies [ index ].topDelay = 0

                                SetSpriteColor ( g_Enemies [ index ].sprite, 255, 255, 255, 0 )

                                if ( g_Level.TimerIncrement <=  10                                   ) then SetEnemyProperties ( 40, index, 1, 100, 8 ) end
                                if ( g_Level.TimerIncrement >=  20 and g_Level.TimerIncrement <=  40 ) then SetEnemyProperties ( 25, index, Random ( 1, 1 ), Random ( 50, 100 ), 8 ) end
                                if ( g_Level.TimerIncrement >=  40 and g_Level.TimerIncrement <=  60 ) then SetEnemyProperties ( 20, index, Random ( 2, 4 ), Random ( 40, 90 ), 8 ) end
                                if ( g_Level.TimerIncrement >=  60 and g_Level.TimerIncrement <=  80 ) then SetEnemyProperties ( 15, index, Random ( 2, 5 ), Random ( 20, 70 ), 6 ) end
                                if ( g_Level.TimerIncrement >=  80 and g_Level.TimerIncrement <= 100 ) then SetEnemyProperties ( 10, index, Random ( 2, 5 ), Random ( 20, 70 ), 6 ) end
                                if ( g_Level.TimerIncrement >= 100 and g_Level.TimerIncrement <= 120 ) then SetEnemyProperties ( 10, index, Random ( 4, 5 ), Random ( 10, 60 ), 4 ) end
                                if ( g_Level.TimerIncrement >= 120                                   ) then SetEnemyProperties ( 10, index, Random ( 4, 5 ), Random ( 10, 60 ), 3 ) end


                                g_LastPopup = i
                                break
                        end
                end

                g_Level.EnemiesUp = g_Level.EnemiesUp + 1

                g_Level.Timer = 0
                g_Level.TimerIncrement = g_Level.TimerIncrement + 2
        end

    for i = 1, 9 do
        if g_Enemies [ i ].state == 1 then HandleEnemyUp   ( i ) end
        if g_Enemies [ i ].state == 2 then HandleEnemyTop  ( i ) end
        if g_Enemies [ i ].state == 3 then HandleEnemyDown ( i ) end
        if g_Enemies [ i ].state == 4 then HandleEnemyHit  ( i ) end
    end
end

function SetEnemyProperties ( limit, index, speed, waitAtTop, delay )

        g_Level.limit = limit

        g_Enemies [ index ].speedUp = speed
        g_Enemies [ index ].speedDown = speed
        g_Enemies [ index ].waitAtTop = waitAtTop
        g_Enemies [ index ].delay = delay
end

function LoadLevel ( level )
        -- load background
        g_Level.background = CreateSprite ( LoadImage ( "mole/background.png" ) )

        -- load foreground
        g_Level.foreground = CreateSprite ( LoadImage ( "mole/foreground.png" ) )
        SetSpritePosition ( g_Level.foreground, 0.0, 80.0 )

        -- pause and play
        g_Level.pause = LoadImage ( "iconpause.png" )
        g_Level.play  = LoadImage ( "iconplay.png" )

        g_Level.pauseButton = CreateSprite ( g_Level.pause )
        SetSpritePosition ( g_Level.pauseButton, 5.0, 5.0 )

        -- enemies
        x = {}
        y = {}

        x [ 1 ] = 1.0
        x [ 2 ] = 121.0
        x [ 3 ] = 241.0
        x [ 4 ] = 1.0
        x [ 5 ] = 121.0
        x [ 6 ] = 241.0
        x [ 7 ] = 1.0
        x [ 8 ] = 121.0
        x [ 9 ] = 241.0

        y [ 1 ] = 231.0
        y [ 2 ] = 231.0
        y [ 3 ] = 231.0
        y [ 4 ] = 331.0
        y [ 5 ] = 331.0
        y [ 6 ] = 331.0
        y [ 7 ] = 431.0
        y [ 8 ] = 431.0
        y [ 9 ] = 431.0

        enemy = 1

        for j = 1, 3 do
                for i = 1, 3 do
                        g_Enemies [ enemy ].sprite    = CreateSprite ( 0 )
                        g_Enemies [ enemy ].state     = 0
                        g_Enemies [ enemy ].delay     = 0
                        g_Enemies [ enemy ].time      = 0
                        g_Enemies [ enemy ].bottomY   = y [ enemy ]
                        g_Enemies [ enemy ].topY      = y [ enemy ] - 45
                        g_Enemies [ enemy ].speedUp   = 1
                        g_Enemies [ enemy ].speedDown = 1
                        g_Enemies [ enemy ].topDelay  = 0
                        g_Enemies [ enemy ].waitAtTop = 100
                        g_Enemies [ enemy ].temp      = 0

                        SetSpritePosition ( g_Enemies [ enemy ].sprite, x [ enemy ], y [ enemy ] )
                        SetSpriteColorAlpha ( g_Enemies [ enemy ].sprite, 0 )

                        for k = 1, 11 do
                                AddSpriteAnimationFrame ( g_Enemies [ enemy ].sprite, g_MoleImages [ k ] )
                        end

                        if ( enemy == 1 or enemy == 2 or enemy == 3 ) then SetSpriteDepth ( g_Enemies [ enemy ].sprite, 7 ) end
                        if ( enemy == 4 or enemy == 5 or enemy == 6 ) then SetSpriteDepth ( g_Enemies [ enemy ].sprite, 5 ) end
                        if ( enemy == 7 or enemy == 8 or enemy == 9 ) then SetSpriteDepth ( g_Enemies [ enemy ].sprite, 3 ) end

                        enemy = enemy + 1
                end
    end

        -- load overlays
        g_Level.overlay1 = CreateSprite ( LoadImage ( "mole/overlay1.png" ) )
        SetSpritePosition ( g_Level.overlay1, 0.0, 250.0 )
        SetSpriteDepth    ( g_Level.overlay1, 6 )

        g_Level.overlay2 = CreateSprite ( LoadImage ( "mole/overlay2.png" ) )
        SetSpritePosition ( g_Level.overlay2, 0.0, 350.0 )
        SetSpriteDepth    ( g_Level.overlay2, 4 )

        g_Level.overlay3 = CreateSprite ( LoadImage ( "mole/overlay3.png" ) )
        SetSpritePosition ( g_Level.overlay3, 0.0, 450.0 )
        SetSpriteDepth    ( g_Level.overlay3, 2 )

        -- move item to front of screen
        g_Item.state = 0
        SetSpritePosition ( g_Item.sprite, -150, 15 )
        SetSpriteDepth ( g_Item.sprite, 0 )

        -- miss icon
        g_Level.miss = CreateSprite ( LoadImage ( "miss.png" ) )
        SetSpritePosition ( g_Level.miss, -200.0, -200.0 )
        SetSpriteDepth ( g_Level.miss, 1 )

        -- score text
        g_Level.scoreText = CreateText ( "0" )
        SetTextSize     ( g_Level.scoreText, 24.0 )
        SetTextPosition ( g_Level.scoreText, 188.0, 10.0 )

        -- timer text
        g_LevelTtimerText = CreateText ( "60" )
        SetTextSize     ( g_LevelTtimerText, 24.0 )
        SetTextPosition ( g_LevelTtimerText, 85.0, 10.0 )

        -- misc text
        g_Level.miscText = CreateText ( "" )
        SetTextSize     ( g_Level.miscText, 24.0 )
        SetTextPosition ( g_Level.miscText, -200.0, -200.0 )

        -- continue text
        g_Level.continueText = CreateText ( "CONTINUE" )
        SetTextSize     ( g_Level.continueText, 24.0 )
        SetTextPosition ( g_Level.continueText, -200.0, -200.0 )
        SetTextDepth    ( g_Level.continueText, 1 )
        SetTextColor    ( g_Level.continueText, 255, 255, 255, 0 )

        -- main menu text
        g_Level.mainMenuText = CreateText ( "MAIN MENU" )
        SetTextSize     ( g_Level.mainMenuText, 24.0 )
        SetTextPosition ( g_Level.mainMenuText, -200.0, -200.0 )
        SetTextDepth    ( g_Level.mainMenuText, 1 )
        SetTextColor    ( g_Level.mainMenuText, 255, 255, 255, 0 )

        g_Level.TimeLimit = 60
        g_Level.Limit     = 40
        g_Level.Timer     = ( g_Level.Limit / 100 ) * 95
        g_LastPopup      = -1

        g_Level.targetHit      = 40
        g_Level.targetAccuracy = 40

        g_State = ePlayLevel
end

function DisplayStartGame ( )
        -- fade in
        alpha = GetSpriteColorAlpha ( g_Overlay )

        if alpha < 255 - 4 then
                alpha = alpha + 4
                SetSpriteColor ( g_Overlay, 255, 255, 255, alpha )
        else
                for i = 1, 5 do
                        SetTextVisible ( g_Text [ i ], 0 )
                end

                g_State = eLoadLevel
        end

        UpdateItems   ( )
        UpdateClouds  ( )
        UpdateEnemies ( )
end

function DisplayMainContents ( )
    if GetPointerPressed ( ) == 1 then
        x = GetPointerX ( )
        y = GetPointerY ( )

        if x >= 80 and x < 220 and y > 190 and y < 240 then
            g_State = eDisplayStartGame
        end
    end

    UpdateItems   ( )
    UpdateClouds  ( )
    UpdateEnemies ( )
end

function DisplayFadeIn ( )
        -- fade in
        alpha = GetSpriteColorAlpha ( g_Overlay )

        if alpha > 4 then
                alpha = alpha - 4
                SetSpriteColor ( g_Overlay, 255, 255, 255, alpha )
        else
                g_State = eDisplayMainMenu
        end

        UpdateItems   ( )
        UpdateClouds  ( )
        UpdateEnemies ( )
end

function UpdateItems ( )
    -- update the item scrolling across the screen (balloon for main menu)

    -- idle state
    if g_Item.state == 0 then

        -- get ready to launch the balloon
        if Random ( 0, 50 ) == 25 then

            -- move right or left
            if Random ( 0, 2 ) == 0 then
                SetSpritePosition ( g_Item.sprite, -150, 15 )
                SetSpriteFlip ( g_Item.sprite, 0, 0 )
                g_Item.direction = 0
            else
                SetSpritePosition ( g_Item.sprite, 360, 15 )
                SetSpriteFlip ( g_Item.sprite, 1, 0 )
                g_Item.direction = 1
            end

            PlaySprite ( g_Item.sprite, 12, 1, 1, 5 )

            g_Item.state = 1
        end
    end

    -- flying state
    if g_Item.state == 1 then

        x = GetSpriteX ( g_Item.sprite )

        if g_Item.direction == 0 then
            x = x + 2
        else
            x = x - 2
        end

        SetSpriteX ( g_Item.sprite, x )

        -- check for tap at this point
        if GetPointerPressed ( ) == 1 then

            if GetSpriteHitTest ( g_Item.sprite, GetPointerX ( ), GetPointerY ( ) ) == 1 then

                                PlaySound ( 6 )

                PlaySprite ( g_Item.sprite, 5, 0, 6, 11 )
                g_Item.state = 2

                if g_State == ePlayLevel then
                                        g_Level.score = g_Level.Score + 25
                end

            end

        end

        -- check for moving off screen
        if g_Item.direction == 0 and x >  420 then g_Item.state = 0 end
        if g_Item.direction == 1 and x < -150 then g_Item.state = 0 end
    end

    if g_Item.state == 2 then
        SetSpriteColorAlpha ( g_Item.sprite, GetSpriteColorAlpha ( g_Item.sprite ) - 2 )

        if GetSpriteCurrentFrame ( g_Item.sprite ) == 10 then
            g_Item.state = 3
        end
    end

    if g_Item.state == 3 then
        SetSpriteColorAlpha ( g_Item.sprite, 255 )
        SetSpritePosition ( g_Item.sprite, -150, 30 )

        g_Item.state = 0
    end
end

function UpdateClouds ( )
        SetSpriteX ( g_Clouds [ 1 ], GetSpriteX ( g_Clouds [ 1 ] ) - 2.0 )
        SetSpriteX ( g_Clouds [ 2 ], GetSpriteX ( g_Clouds [ 2 ] ) - 1.0 )
        SetSpriteX ( g_Clouds [ 3 ], GetSpriteX ( g_Clouds [ 3 ] ) - 3.0 )

        if ( GetSpriteX ( g_Clouds [ 1 ] ) < -100.0 ) then SetSpriteX ( g_Clouds [ 1 ], 350.0 + Random ( 0, 200 ) ) end
        if ( GetSpriteX ( g_Clouds [ 2 ] ) < -100.0 ) then SetSpriteX ( g_Clouds [ 2 ], 500.0 + Random ( 0, 200 ) ) end
        if ( GetSpriteX ( g_Clouds [ 3 ] ) < -100.0 ) then SetSpriteX ( g_Clouds [ 3 ], 400.0 + Random ( 0, 200 ) ) end
end

function UpdateEnemies ( )
    count = 0

        for i = 10, 12 do
                if ( g_Enemies [ i ].state == 0 ) then
                        count = count + 1
                end
        end

        if ( count == 3 and Random ( 0, 20 ) == 10 ) then
                i = Random ( 10, 12 )
        
                if ( i ~= g_LastPopup ) then
                        g_Enemies [ i ].topDelay = 0
                        g_Enemies [ i ].state = 1
                        g_LastPopup = i
                end
        end

        for i = 10, 12 do
          if g_Enemies [ i ].state == 1 then HandleEnemyUp   ( i ) end
          if g_Enemies [ i ].state == 2 then HandleEnemyTop  ( i ) end
          if g_Enemies [ i ].state == 3 then HandleEnemyDown ( i ) end
          if g_Enemies [ i ].state == 4 then HandleEnemyHit  ( i ) end
        end

    if GetPointerPressed ( ) == 1 then
        for i = 10, 12 do
           if ( g_Enemies [ i ].state == 1 or g_Enemies [ i ].state == 2 or g_Enemies [ i ].state == 3 ) then

                if GetSpriteColorAlpha ( g_Enemies [ i ].sprite ) < 20 then
                    break
                end

                if ( GetSpriteHitTest ( g_Enemies [ i ].sprite, GetPointerX ( ), GetPointerY ( ) ) == 1 ) then

                                        PlaySound ( Random ( 1, 5 ) )

                    StopSprite ( g_Enemies [ i ].sprite )
                    g_Enemies [ i ].temp = 0
                    g_Enemies [ i ].state = 4
                end
           end
        end
    end
end

function HandleEnemyUp ( id )
    sprite = g_Enemies [ id ].sprite

        alpha = GetSpriteColorAlpha ( sprite )

        if ( alpha < 255 - 48 ) then
                alpha = alpha + 48
        end

        x = GetSpriteX ( sprite )
        y = GetSpriteY ( sprite )

        if ( GetSpritePlaying ( sprite ) == 0 ) then
                PlaySprite ( sprite, 5, 1, 1, 4 )
        end

        SetSpriteColorAlpha ( sprite, alpha )

    ---- see if we need to continue moving the sprite up
        if ( y > g_Enemies [ id ].topY + g_Enemies [ id ].speedUp ) then
                SetSpritePosition ( sprite, x, y - g_Enemies [ id ].speedUp )
        else
                ---- we are the top, move onto the next phase
                SetSpriteColorAlpha ( sprite, 255 )

        ---- stop animation
                StopSprite ( sprite )

        g_Enemies [ id ].state = 2
                g_Enemies [ id ].time  = 0
        end
end

function HandleEnemyTop ( id )
    sprite = g_Enemies [ id ].sprite

        if ( GetSpritePlaying ( sprite ) == 0 ) then
                PlaySprite ( sprite, 5, 1, 5, 7 )
        end

    g_Enemies [ id ].topDelay = g_Enemies [ id ].topDelay + 1

        if ( g_Enemies [ id ].topDelay > g_Enemies [ id ].waitAtTop ) then
                StopSprite ( sprite )

                g_Enemies [ id ].state = 3
                g_Enemies [ id ].time  = 0
        end

end

function HandleEnemyDown ( id )
    sprite = g_Enemies [ id ].sprite

        alpha = GetSpriteColorAlpha ( sprite )

        x = GetSpriteX ( sprite )
        y = GetSpriteY ( sprite )

        if ( GetSpritePlaying ( sprite ) == 0 ) then
                PlaySprite ( sprite, 5, 1, 1, 4 )
        end

        if ( y < g_Enemies [ id ].bottomY - g_Enemies [ id ].speedDown ) then
                SetSpritePosition ( sprite, x, y + g_Enemies [ id ].speedDown )
        else
                if ( alpha > 48 ) then
                        alpha = alpha - 48
                        SetSpriteColorAlpha ( sprite, alpha )
                else
                        SetSpriteColorAlpha ( sprite, 0 )

                        g_Enemies [ id ].state = 0
        end
    end
end

function HandleEnemyHit ( id )
    sprite = g_Enemies [ id ].sprite
    y = GetSpriteY ( sprite )

    alpha = GetSpriteColorAlpha ( sprite )

    SetSpriteColor ( sprite, 200, 100, 100, alpha )

        if ( GetSpritePlaying ( sprite ) == 0 ) then
                PlaySprite ( sprite, 5, 1, 8, 10 )
    end

    if ( y < g_Enemies [ id ].bottomY - 20.0 ) then
                SetSpriteY ( sprite, y + 6.0 )
        end

        if ( GetSpriteCurrentFrame ( sprite ) == 10 ) then
                g_Enemies [ id ].temp = g_Enemies [ id ].temp + 1
    end

        if ( g_Enemies [ id ].temp > 24 ) then
                if ( alpha > 24 ) then
                        alpha = alpha - 24
                        SetSpriteColor ( sprite, 200, 100, 100, alpha )
        else
            g_Enemies [ id ].temp = 0
            g_Enemies [ id ].state = 0
            g_Enemies [ id ].time = 0
            g_Enemies [ id ].delay = 12

                        StopSprite ( sprite )

                        SetSpriteColor ( sprite, 255, 255, 255, 0 )

                        SetSpriteY ( sprite, g_Enemies [ id ].bottomY )
                end
        end
end

function SetupMainMenu ( )
    SetVirtualResolution ( 320, 480 )

    -- use a new font for the default text
    defaultfontimage = LoadImage ( "ascii.png" )
    SetTextDefaultFontImage ( defaultfontimage )

    -- background image
    background = CreateSprite ( LoadImage ( "main_menu/background.png" ) )
    SetSpritePosition ( background, 0, 0 )

    -- foreground image
    foreground = CreateSprite ( LoadImage ( "main_menu/foreground.png" ) )
    SetSpritePosition ( foreground, 0, 370 )

    -- smack it logo
    logo = CreateSprite ( LoadImage ( "main_menu/logo.png" ) )
    SetSpritePosition ( logo, 69, 0 )

    -- balloon moving across the screen
    g_Item.sprite = CreateSprite ( 0 )
    g_Item.state = 0

    for i = 1, 5 do
        AddSpriteAnimationFrame ( g_Item.sprite, LoadImage ( "items/item" .. string.format("%d", i - 1 ) .. ".png" ) )
    end

    for i = 1, 6 do
        AddSpriteAnimationFrame ( g_Item.sprite, LoadImage ( "items/smoke" .. string.format("%d", i - 1 ) .. ".png" ) )
    end

    SetSpritePosition ( g_Item.sprite, -150, 30 )

        g_MoleImages [  1 ] = LoadImage ( "mole/looking0.png" )
        g_MoleImages [  2 ] = LoadImage ( "mole/looking1.png" )
        g_MoleImages [  3 ] = LoadImage ( "mole/looking2.png" )
        g_MoleImages [  4 ] = LoadImage ( "mole/looking3.png" )
        g_MoleImages [  5 ] = LoadImage ( "mole/wave0.png" )
        g_MoleImages [  6 ] = LoadImage ( "mole/wave1.png" )
        g_MoleImages [  7 ] = LoadImage ( "mole/wave2.png" )
        g_MoleImages [  8 ] = LoadImage ( "mole/wave3.png" )
        g_MoleImages [  9 ] = LoadImage ( "mole/hit0.png" )
        g_MoleImages [ 10 ] = LoadImage ( "mole/hit1.png" )
        g_MoleImages [ 11 ] = LoadImage ( "mole/hit2.png" )

    for i = 10, 12 do
        g_Enemies [ i ].sprite    = CreateSprite ( 0 )
        g_Enemies [ i ].state     = 0
        g_Enemies [ i ].delay     = 0
        g_Enemies [ i ].time      = 0
        g_Enemies [ i ].bottomY   = 431
        g_Enemies [ i ].topY      = 386
        g_Enemies [ i ].speedUp   = 1
        g_Enemies [ i ].speedDown = 1
        g_Enemies [ i ].topDelay  = 0
        g_Enemies [ i ].waitAtTop = 100
        g_Enemies [ i ].temp      = 0

        if i == 10 then SetSpritePosition ( g_Enemies [ i ].sprite,  -2, 431 ) end
        if i == 11 then SetSpritePosition ( g_Enemies [ i ].sprite, 118, 431 ) end
        if i == 12 then SetSpritePosition ( g_Enemies [ i ].sprite, 238, 431 ) end

        for j = 1, 11 do
            AddSpriteAnimationFrame ( g_Enemies [ i ].sprite, g_MoleImages [ j ] )
        end

        PlaySprite ( g_Enemies [ i ].sprite, 12, 1, 1, 4 )
        SetSpriteColorAlpha ( g_Enemies [ i ].sprite, 0 )
    end

    -- overlay at bottom of the screen
    overlay = CreateSprite ( LoadImage ( "main_menu/overlay.png" ) )
    SetSpritePosition ( overlay, 0, 450 )

    -- clouds
    g_Clouds [ 1 ] = CreateSprite ( LoadImage ( "main_menu/cloud1.png" ) )
    g_Clouds [ 2 ] = CreateSprite ( LoadImage ( "main_menu/cloud2.png" ) )
    g_Clouds [ 3 ] = CreateSprite ( LoadImage ( "main_menu/cloud3.png" ) )

    SetSpritePosition ( g_Clouds [ 1 ], 350, 330 )
    SetSpritePosition ( g_Clouds [ 2 ], 500, 200 )
    SetSpritePosition ( g_Clouds [ 3 ], 400, 130 )

    -- text
    g_Text [ 1 ] = CreateText ( "SMACK IT" )
        g_Text [ 2 ] = CreateText ( "START" )
        g_Text [ 3 ] = CreateText ( "" )
        g_Text [ 4 ] = CreateText ( "" )
        g_Text [ 5 ] = CreateText ( "" )

        for i = 1, 5 do
                SetTextSize ( g_Text [ i ], 24.0 )
        end

        space = 50

        SetTextPosition ( g_Text [ 1 ], 15.0, -230.0 )
        SetTextPosition ( g_Text [ 2 ], 90.0, 200.0 )
        SetTextPosition ( g_Text [ 3 ], 70.0, 160.0 + ( space * 1 ) )
        SetTextPosition ( g_Text [ 4 ], 30.0, 160.0 + ( space * 2 ) )
        SetTextPosition ( g_Text [ 5 ], 30.0, 160.0 + ( space * 3 ) )

        g_Overlay = CreateSprite ( LoadImage ( "black.jpg" ) )
        SetSpritePosition ( g_Overlay, 0.0, 0.0 )
        SetSpriteSize ( g_Overlay, 320, 480 )

        LoadMusic ( 1, "rag.mp3" )
        PlayMusic ( 1, 1 )

        LoadSound ( 1, "hit1.wav" )
        LoadSound ( 2, "hit2.wav" )
        LoadSound ( 3, "hit3.wav" )
        LoadSound ( 4, "hit4.wav" )
        LoadSound ( 5, "hit5.wav" )

        LoadSound ( 6, "hitPlane.wav" )
        LoadSound ( 7, "miss.wav" )
        LoadSound ( 8, "warning.wav" )
end