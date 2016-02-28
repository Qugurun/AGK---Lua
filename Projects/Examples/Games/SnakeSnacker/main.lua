--Declare globals
xsize = 0
ysize = 0
scaler = 0
xapple = 0
yapple = 0
applex = 0
appley = 0
dietx = 0
diety = 0
rockstart = 0
rockend = 0
zz = 0
xx = 0
yy = 0
touch = 0
time = 0
eaten = 0
gappletime = 0
diettime = 0
gameIsPaused = 0
gameover = 0
entity = {}
grid = {}
rocks = {}
snake_segs = {}

gameStarted = 0


function Setup()
  --Set the media folder as the current directory
  SetCurrentDir("media")
  
  --Initialize array tables to 0
  for i = 1, 40 do
    entity[i] = {}
    for x = 1, 20 do
      entity[i][x] = 0;
    end
  end  
  for x = 1, 30 do
    rocks[x] = 0;
  end
  for i = 1, 400 do
    snake_segs[i] = {}
    for x = 1, 3 do
      snake_segs[i][x] = 0;
    end
  end 
  
  xsize=23
  ysize=15
  scaler=20
  rockstart=4
  rockend=8
  
  if GetDeviceWidth() == 320 or GetDeviceWidth() == 480 then
      xsize=14 
      ysize=9 
      scaler=32
      rockend=6
  end
  
  --rem Checks to see if device is touch based
  if GetKeyboardExists() == 1 then
    touch=0
  else
    touch=1
  end
  
  ClearGrid()
  
  --Rem Load high score
  if GetFileExists("snakescore.txt") == 1 then
    OpenToRead(1, "snakescore.txt")
    highscore = ReadInteger(1)
    CloseFile(1)
  else
   highscore = 0
  end
  
  SetOrientationAllowed(0,0,1,1)
  SetVirtualResolution(480,320)
  
  --rem Loading splash (Samsung Bada blank screen when loading)
  CreateSprite ( 98765, LoadImage ( "loading.png" ) )
  SetSpriteSize ( 98765, 480, 320 )
  Sync() 
  Sync()
  Sleep(500)
  
  LoadMusicFiles()
  LoadImages()
  MakeGameText()
  
  StartGame()
end

function StartGame()
  --rem variable setups
  apple=0 
  applex=1
  appley=1
  gamespeed=18
  gapple=0 
  gapplex=1
  gappley=1
  diet=0
  dietx=1 
  diety=1
  slowtime=0 
  slowx=1
  slowy=1
  entity[1][5]=2
  gameover=0 
  snakesize=3 
  snake_xd=1
  snake_yd=0
  score=0
  gameIsPaused = 0


  --rem Set x,y and angle of snake segs
  for i=1, snakesize do
      snake_segs[i][1]=6-i 
      snake_segs[i][2]=5 
      snake_segs[i][3]=0
      gx=6-i
      gy=5
      grid[gx][gy]=1
  end


  --rem ******************************************************
  --rem             Main Menu
  --rem ******************************************************
  GameSpritesInvisible()
  ShowMenu()
  
  gameStarted = 0
end

function Update()
  if gameStarted == 0 then
    gameStarted = GetPointerPressed()
    if gameStarted == 1 then
      GameBegin()
    end
  else
    if gameover == 1 then
      red=Random(1,255)
      blue=Random(1,255)
      green=Random(1,255)
      SetTextColor(2,red,green,blue,255)
      SetTextColor(3,red,green,blue,255)
      SetTextColor(4,red,green,blue,255)
      SetTextColor(5,red,green,blue,255)
      
      if (GetPointerPressed() == 1) then
        ShowMenu()
        StopMusic()
        SetTextVisible(2,0)
        SetTextVisible(3,0)
        SetTextVisible(4,0)
        SetTextVisible(5,0)
        
        StartGame()
      end
      
      Sync()
      return
    end
    
    if gameIsPaused == 0 then
      --rem ******************************************************
      --rem              Main Loop of the Game
      --rem ****************************************************** 
      if score>highscore then
          highscore=score
      end
      --rem fade in apple, golden apple and pill
      fadein(2,6)     --gold apple
      fadeout(2,6)

      fadein(3,6)     --pill
      fadeout(3,6)


      fadein(20,6)    --slow
      fadeout(20,6)

      --rem update score
      SetTextString (3,string.format("%d", score))
      SetTextString (5,string.format("%d",highscore))

      --rem draw apple
      SetSpritePosition(500,applex*scaler,appley*scaler)

      --rem draw golden apple
      SetSpritePosition(499,gapplex*scaler,gappley*scaler)

      --rem draw diet pill
      SetSpritePosition(498,dietx*scaler,diety*scaler)

      --rem draw slow down
      SetSpritePosition(slowid,entity[20][1]*scaler,entity[20][2]*scaler)

      --rem draw blocks
      count=1
      for i=rockstart, rockend do
        SetSpritePosition(entity[i][7],entity[i][1]*scaler,entity[i][2]*scaler)
        count = count + 1
      end
      
      --rem draw snake
      for i=1, snakesize do
        SetSpriteVisible(i,1)
        if i>1 and i<snakesize then
          SetSpriteImage(i,2,1)
          r1=snake_segs[i-1][3]
          r2=snake_segs[i][3]

          if r1==90 and r2~=90 then
              SetSpriteImage(i,3,1)
          end
          if r1==180 and r2~=180 then
              SetSpriteImage(i,3,1)
          end
          if r1==270 and r2~=270 then
              SetSpriteImage(i,3,1)
          end
          if r1==0 and r2~=0 then
              SetSpriteImage(i,3,1)
          end
        end
        --rem force the head and tail to be used
        if i == 1 then
          SetSpriteImage(i,1,1) 
        end
        if i==snakesize then
            SetSpriteImage(i,4,1)
            snake_segs[i][3]=snake_segs[i-1][3]
        end
        --rem position the segment on screen
        SetSpritePosition(i,snake_segs[i][1]*scaler,snake_segs[i][2]*scaler)
        --rem ensure the proper rotation
        z=snake_segs[i][3]
        if i~=1 and i~=snakesize then
          if r2==0 and r1==90 then
            z=270
          end
          if r2==90 and r1==180 then 
            z=0
          end
          if r2==180 and r1==270 then
            z=90 
          end
          if r2==270 and r1==0 then 
            z=z+270 
          end
        end
        SetSpriteAngle(i,z)
      end

      --rem ********************************************
      --rem    MOVE if time is right - SNAKE LOGIC!
      --rem ********************************************
      if time==gamespeed then
        time=0
        --Clear the snake from the grid
        for i=1, snakesize do
          gx=snake_segs[i][1]
          gy=snake_segs[i][2]
          grid[gx][gy]=0
        end

        --rem Now move the head in the direction chosen by the player
        xtemp=snake_segs[1][1]
        ytemp=snake_segs[1][2]

        --rem Checks if a snake's head is eating another part of the snake
        gameover=0
        for i=2, snakesize do
            x1=snake_segs[i][1]
            y1=snake_segs[i][2]
            if xtemp==x1 and ytemp==y1 then
                gameover=1
            end
        end

        xtemp=xtemp+snake_xd
        ytemp=ytemp+snake_yd
        direc_change=0

        --rem If head goes off screen, place it at opposite end
        if xtemp<0 then
            xtemp=xsize
        end
        if xtemp>xsize then
            xtemp=0
        end
        if ytemp<0 then
            ytemp=ysize
        end
        if ytemp>ysize then
            ytemp=0
        end
        
        --rem First copy the position of each segment to it's partner segment
        for i=snakesize, 2, -1 do
          snake_segs[i][1]=snake_segs[i-1][1]
          snake_segs[i][2]=snake_segs[i-1][2]
          snake_segs[i][3]=snake_segs[i-1][3]
        end


        snake_segs[1][1]=xtemp
        snake_segs[1][2]=ytemp

        if snake_xd==1 and snake_yd==0 then
          snake_segs[1][3]=0
        end
        if snake_xd==0 and snake_yd==-1 then
          snake_segs[1][3]=270 
        end
        if snake_xd==-1 and snake_yd==0 then
          snake_segs[1][3]=180 
        end
        if snake_xd==0 and snake_yd==1 then
          snake_segs[1][3]=90
        end
      end
      
      --Set grid places for newly positioned snake
      for i=1, snakesize do
        gx=snake_segs[i][1]
        gy=snake_segs[i][2]
        grid[gx][gy]=1
      end
      time = time + 1
      
      --rem *******************************************
      --rem If apple eaten make snake longer
      --rem *******************************************
      if snake_segs[1][1]==applex then
          if snake_segs[1][2]==appley then
              snakesize=snakesize+1 
              score=score+(snakesize+gamespeed) 
              gamespeed=gamespeed-1 
              eaten=eaten+1
              if gamespeed<5 then
                gamespeed=5
              end
              angle=snake_segs[snakesize-1][3]
              if angle==0 then
                xadd=-1 
                yadd=0
              end
              if angle==90 then
                xadd=0
                yadd=-1
              end
              if angle==180 then
                xadd=1 
                yadd=0
              end
              if angle==270 then
                xadd=0
                yadd=1
              end

              snake_segs[snakesize][1]=snake_segs[snakesize-1][1]+xadd
              snake_segs[snakesize][2]=snake_segs[snakesize-1][2]+yadd

              SetParticlesPosition ( 1, applex*scaler+8,appley*scaler+8)
              ResetParticleCount ( 1 )
              SetParticlesFrequency ( 1, 50 )
              SetParticlesLife ( 1, 1.0 )
              SetParticlesSize ( 1, 10 )
              SetParticlesImage ( 1, 7 )
              SetParticlesDirection ( 1, 10, 10 )
              SetParticlesAngle ( 1, 360 )
              SetParticlesVelocityRange ( 1, 0.8, 2.5 )
              SetParticlesMax ( 1, 50 )
              AddParticlesColorKeyFrame ( 1, 0.0, 0, 0, 0, 0 )
              AddParticlesColorKeyFrame ( 1, 0.5, 255, 255, 0, 255 )
              AddParticlesColorKeyFrame ( 1, 2.8, 255, 0, 0, 0 )
              AddParticlesForce ( 1, 2.0, 2.8, 25, -25 )

              --rem Check to make sure new apple is placed in a clear area
              zz=1 
              zz2=0
              repeat
                  xx=Random(1,xsize-1)
                  yy=Random(1,ysize-2)

                  zz=grid[xx][yy]

                  if zz==0 then
                      applex=xx
                      appley=yy
                      grid[xx][yy]=3  --// 3=an apple
                      zz2=1
                  end

                  if zz==1 then

                  end
              until zz2==1

              PlaySound(1)
              entity[1][5]=2
            end
        end 
        --rem *******************************************
        --rem Has the snake hit a BLOCK?
        --rem *******************************************
        for i=rockstart, rockend do
          if snake_segs[1][1]==entity[i][1] then
            if snake_segs[1][2]==entity[i][2] then
              gameover=1
            end
          end
        end
        
        DoSlow()
        DoGApple()
        DoPill()
        
        --rem ****************************************************
        --rem           I N P U T from Player
        --rem ****************************************************
        --rem for touch based devices we will use left and right icons to turn the snake

        if touch==0 then

           key=GetRawKeyPressed(38) --` Up arrow
           if key==1 and snake_yd~=1 and direc_change==0 then
              snake_xd=0
              snake_yd=-1
              direc_change=1
            end

           key=GetRawKeyPressed(40) --` Down
           if key==1 and snake_yd~=-1 and direc_change==0 then
              snake_xd=0
              snake_yd=1
              direc_change=1
            end

           key=GetRawKeyPressed(37) --`Left
           if key==1 and snake_xd~=1 and direc_change==0 then
              snake_xd=-1
              snake_yd=0
              direc_change=1
            end

            key=GetRawKeyPressed(39) --`Right
            if key==1 and snake_xd~=-1 and direc_change==0 then
              snake_xd=1
              snake_yd=0
              direc_change=1
            end
        end

        if GetPointerPressed()==1 and touched==0 then
            hitsprite=GetSpriteHit(GetPointerX(),GetPointerY())
        end
        
        if GetPointerPressed()==0 then
          touched=0
          hitsprite=0
        end
        
        if touch==1 then

          --rem Turn snake to the left if icon pressed.
          if touched==0 then
            if hitsprite==tleft_s then
                if direc_change==0 then
                    if snake_xd==1 then
                        snake_xd=0
                        snake_yd=-1
                        direc_change=1
                        touched=1
                    end
                end
                if direc_change==0 then
                    if snake_xd==-1 then
                        snake_xd=0
                        snake_yd=1
                        direc_change=1
                        touched=1
                    end
                end
                if direc_change==0 then
                    if snake_yd==1 then
                        snake_xd=1
                        snake_yd=0
                        direc_change=1
                        touched=1
                    end
                end
                if direc_change==0 then
                    if snake_yd==-1 then
                        snake_xd=-1
                        snake_yd=0
                        direc_change=1
                        touched=1
                    end
                end
            end

            --rem Turn snake to the right if icon pressed.
            if hitsprite==tright_s then
                if direc_change==0 then
                    if snake_xd==1 then
                        snake_xd=0
                        snake_yd=1
                        direc_change=1
                        touched=1
                    end
                end
                if direc_change==0 then
                    if snake_xd==-1 then
                        snake_xd=0
                        snake_yd=-1
                        direc_change=1
                        touched=1
                    end
                end
                if direc_change==0 then
                    if snake_yd==1 then
                        snake_xd=-1
                        snake_yd=0
                        direc_change=1
                        touched=1
                    end
                end
                if direc_change==0 then
                    if snake_yd==-1 then
                        snake_xd=1
                        snake_yd=0
                        direc_change=1
                        touched=1
                    end
                end
            end
          end
      end
       
      --rem If user presses / clicks Pause then go into pause mode
      if touched==0 then
          if hitsprite==pause_s then
            PauseMusic()
            GameSpritesDimmed()
            SetSpriteVisible(pausetext_s,1)

            gameIsPaused = 1
          end
      end
      
      if gameover == 1 then
        GameOver()
      end
    else
      --` Wait until touch is released
      hitsprite=GetSpriteHit(GetPointerX(),GetPointerY())
      if GetPointerPressed()==1 and hitsprite~=pause_s then
          ResumeMusic()
          GameSpritesUndimmed()
          SetSpriteVisible(pausetext_s,0)
          gameIsPaused = 0
      end
    end
  end

  Sync()
end

function GameOver()
--rem ****************** G A M E O V E R *********************

  StopMusic()
  for i=1, 100 do
    if i==10 then
      PlaySound(6)
    end
    Sync()
  end
  PlayMusic(3)

  ResetSlow()
  ResetGApple()
  ResetPill()

  GameSpritesInvisible()

  for i=1, 100 do --rem snakesize
    snake_segs[i][1]=-50
    snake_segs[i][2]=-50
    SetSpritePosition(i,snake_segs[i][1],snake_segs[i][2])
  end
  ShowGameOver()


  OpenToWrite(1,"snakescore.txt")
  WriteInteger(1,highscore)
  CloseFile(1)
end

function ResetSlow()
  entity[20][4]=0              --//Set slow to not alive now
  entity[20][5]=3              --//Set to fade to zero vis
  entity[20][6]=0
  SetSpriteColorAlpha(entity[20][7],0)
end

function ResetGApple()
  entity[2][4]=0              --//Set slow to not alive now
  entity[2][5]=3              --//Set to fade to zero vis
  entity[2][6]=0
  SetSpriteColorAlpha(entity[2][7],0) 
end

function ResetPill()
  entity[3][4]=0              --//Set slow to not alive now
  entity[3][5]=3              --//Set to fade to zero vis
  entity[3][6]=0
  SetSpriteColorAlpha(entity[3][7],0)
end

function ShowGameOver()
  SetSpriteVisible(501,0)
  SetSpritePosition ( 501, 0, -9999 )
  SetSpriteVisible(601,0) 
  SetSpritePosition ( 601, 480-50, -9999 )
  SetSpriteVisible(504,1)
  SetSpritePosition ( 504, 0, 0 )
  SetSpriteVisible(503,0)
  SetSpritePosition ( 503, 0, -9999 )
  SetSpriteVisible(touch_s,1)
  StopMusic()
  PlayMusic(3)
  SetTextPosition(2,120,250)
  SetTextPosition(3,175,250)
  SetTextPosition(4,240,250)
  SetTextPosition(5,340,250)
end

function GameSpritesInvisible()
  --// Hide Snake
  for i=1, 100 do
      SetSpriteVisible(i,0)
  end
  --// Hide Rocks
  count=1
  for i=rockstart, rockend do
    SetSpriteVisible(rocks[count],0)
    count = count + 1
  end
  --// Hide Diet Pill
  SetSpriteVisible(498,0)
  --// Hide Slow down
  SetSpriteVisible(slowid,0)
  --// Hide Gold Apple
  SetSpriteVisible(499,0)
  --// Hide Apple
  SetSpriteVisible(500,0)
  --// Hide Game Backdrop
  SetSpriteVisible(503,0)
  SetSpritePosition ( 503, 0, -9999 )
  --// Hide Left and Right
  if touch==1 then
      SetSpriteVisible(tright_s,0)
      SetSpriteVisible(tleft_s,0)
  end
  --//Hide Pause
  SetSpriteVisible(pause_s,0)  
end

function GameSpritesUndimmed()
  for i=1, 100 do
      SetSpriteColorAlpha(i,255)
  end
  count=1
  for i=rockstart, rockend do
    SetSpriteColorAlpha(rocks[count],255)
    count = count + 1
  end
  SetSpriteColorAlpha(498,alph498)
  SetSpriteColorAlpha(slowid,255)
  SetSpriteColorAlpha(499,alph499)
  SetSpriteColorAlpha(500,alph500)
  SetSpriteColorAlpha(503,200)
  if touch==1 then
    SetSpriteColorAlpha(tleft_s,150)
    SetSpriteColorAlpha(tright_s,150)
  end
end

function GameSpritesDimmed()
  for i=1, 100 do
    SetSpriteColorAlpha(i,100)
  end
  count=1
  for i=rockstart, rockend do
    SetSpriteColorAlpha(rocks[count],100)
    count = count + 1
  end
  alph498=GetSpriteColorAlpha(498)
  alph499=GetSpriteColorAlpha(499)
  alph500=GetSpriteColorAlpha(500)

  for i=498, 500 do
      if GetSpriteColorAlpha(i)-100 < 0 then
          alph=GetSpriteColorAlpha(i)
      else
          alph=GetSpriteColorAlpha(i)-100
      end
    SetSpriteColorAlpha(i,alph)
  end
  SetSpriteColorAlpha(503,100)
  SetSpriteColorAlpha(slowid,100)
  if touch==1 then
    SetSpriteColorAlpha(tleft_s,100)
    SetSpriteColorAlpha(tright_s,100)
  end
end

function DoPill()
  if diet==1 then
    if snake_segs[1][1]==dietx then
        if snake_segs[1][2]==diety then
            if snakesize>3 then
                s=snakesize
                snakesize=snakesize-3
                if snakesize<3 then
                  snakesize=3
                end

                for i=snakesize, s do
                  SetSpriteVisible(i,0)
                end

            end
            diet=0

            angle=snake_segs[snakesize-1][3]
            if angle==0 then
                xadd=-1
                yadd=0
            end
            if angle==90 then
                xadd=0 
                yadd=-1
            end
            if angle==180 then
                xadd=1
                yadd=0
            end
            if angle==270 then
                xadd=0 
                yadd=1
            end

            snake_segs[snakesize][1]=snake_segs[snakesize-1][1]+xadd
            snake_segs[snakesize][2]=snake_segs[snakesize-1][2]+yadd
            PlaySound(3)
            PlaySound(4)
            entity[3][4]=0
            entity[3][5]=3
            entity[3][6]=0
            SetSpriteVisible(498,0)
        end
    end
  end

  --rem should we create a diet pill (a rare thing indeed!)
  if diet==0 then
        r=Random(1,500)
        if r==20 then
          diet=1
          diettime=Random(120,190)

          zz=1 
          zz2=0
          repeat
              xx=Random(1,xsize-1)
              yy=Random(1,ysize-2)
              zz=grid[xx][yy]
              if zz==0 then
                  dietx=xx
                  diety=yy
                  grid[xx][yy]=6  --// 6=Pill
                  zz2=1
              end
          until zz2==1
          entity[3][4]=1
          entity[3][5]=1
          SetSpriteVisible(498,1)
          PlaySprite ( 498, 60, 1, 1, 15 )
        end
  end

  --rem Countdown to see if diet pill should be removed
  diettime=diettime-1
  if entity[3][5]==3 then
      diet=0
      xx=dietx
      yy=diety
      grid[xx][yy]=0
      SetSpriteColorAlpha(entity[3][7],0)
  end
  if diettime<=0 then
      entity[3][5]=0
  end
end

function DoGApple()
    --rem If GOLDEN apple eaten!
    if gapple==1 then
        if snake_segs[1][1]==gapplex then
            if snake_segs[1][2]==gappley then
                snakesize=snakesize+1
                score=score+(snakesize+gamespeed*5)

                angle=snake_segs[snakesize-1][3]
                if angle==0 then
                  xadd=-1
                  yadd=0
                end
                if angle==90 then
                    xadd=0
                    yadd=-1
                end
                if angle==180 then
                    xadd=1
                    yadd=0
                end
                if angle==270 then
                    xadd=0
                    yadd=1
                end

                snake_segs[snakesize][1]=snake_segs[snakesize-1][1]+xadd
                snake_segs[snakesize][2]=snake_segs[snakesize-1][2]+yadd

                SetParticlesPosition ( 1, gapplex*scaler+8,gappley*scaler+8)

                ResetParticleCount ( 1 )
                SetParticlesFrequency ( 1, 50 )
                SetParticlesLife ( 1, 1.0 )
                SetParticlesSize ( 1, 10 )
                SetParticlesImage ( 1, 7 )
                SetParticlesDirection ( 1, 10, 10 )
                SetParticlesAngle ( 1, 360 )
                SetParticlesVelocityRange ( 1, 0.8, 2.5 )
                SetParticlesMax ( 1, 50 )
                AddParticlesColorKeyFrame ( 1, 0.0, 0, 0, 0, 0 )
                AddParticlesColorKeyFrame ( 1, 0.5, 0, 255, 0, 255 )
                AddParticlesColorKeyFrame ( 1, 2.8, 255, 0, 0, 0 )
                AddParticlesForce ( 1, 3.0, 3.8, 25, -25 )
                entity[2][4]=0
                entity[2][5]=3
                entity[2][6]=0
                SetSpriteVisible(499,0)
                PlaySound(2)
                PlaySound(5)
            end
        end
    end


    --rem Should we create a new golden apple?
    if gapple==0 then
        if eaten>=2 then     --` Make sure player has eaten at least two red apples before creating a new gold one
            r=Random(1,500)
            if r==50 then
                gapple=1
                gappletime=Random(200,300)
                eaten=0
                zz=1
                zz2=0
                repeat
                    xx=Random(1,xsize-1)
                    yy=Random(1,ysize-2)

                    zz=grid[xx][yy]

                    if zz==0 then
                        gapplex=xx
                        gappley=yy
                        grid[xx][yy]=4  --// 4=Golden apple
                        zz2=1
                    end
                until zz2==1
                entity[2][4]=1
                entity[2][5]=1
                SetSpriteVisible(499,1)
            end
        end
    end

  --rem Countdown to see if golden apple should be removed
  gappletime=gappletime-1


  if entity[2][5]==3 then
      gapple=0
      xx=gapplex
      yy=gappley
      grid[xx][yy]=0
      SetSpriteColorAlpha(entity[2][7],0)
  end

  if gappletime<=0 then
      entity[2][5]=0
  end
end

function DoSlow()
  --rem Has the snake hit a slow down?
  if entity[20][4]==1 then              --check to make sure slow is live
      if snake_segs[1][1]==entity[20][1] then
          if snake_segs[1][2]==entity[20][2] then
              slowdown=0                  --Set flag so a new SLOW can be created later
              entity[20][4]=0              --Set slow to not alive now
              entity[20][5]=3              --Set to fade to zero vis
              entity[20][6]=0
              SetSpriteColorAlpha(entity[20][7],0)
              PlaySound(3)

              xx=entity[20][1]             --Clear the grid
              yy=entity[20][2]
              SetSpriteVisible(slowid,0)
              grid[xx][yy]=0
              gamespeed=gamespeed+1       --Slow the snake a little
              if gamespeed>15 then             --Not too much mind
                  gamespeed=15
              end
          end
      end
  end

  --` should we create a slow down pickup
  --` slowdown flag 0=create a new slow pickup, 1=pick up is live
  --` slowtime = time the pick up is alive
  if slowdown==0 then
      r=Random(300,500)
      if r==400 then
          slowdown=1 
          slowtime=Random(400,700)
          zz=1 
          zz2=0
          repeat
              xx=Random(1,xsize-1)
              yy=Random(1,ysize-2)
              zz=grid[xx][yy]
              if zz==0 then
                  entity[20][1]=xx
                  entity[20][2]=yy
                  grid[xx][yy]=5  --// 5=Slow down
                  zz2=1
              end
          until zz2==1
          entity[20][4]=1  --// Entity is Live!
          entity[20][5]=1  --// Fade in
          SetSpriteVisible(slowid,1)
      end
  end
  if entity[20][5]==3 then
      slowdown=0
      xx=entity[20][1]             --//clear the grid
      yy=entity[20][2]
      grid[xx][yy]=0
  end

  -- decrease time of pickup, if zero, set the pick up to fade off
  slowtime=slowtime-1
  if slowtime<=0 then
    entity[20][5]=0      --//Fade out
  end
end

function GameBegin()
  ShowGame()
  GameSpritesVisible()
    
  --rem ******************************************************
  --rem          Place the rocks down first!
  --rem ******************************************************
  for ii=rockstart, rockend do
      zz2=0
      repeat
          xx=Random(1,xsize-1)
          yy=Random(1,ysize-1)
          if yy==5 then --  // stops blocks being set to the same line as the snake at start
              yy=6
          end

          zz=grid[xx][yy]

          if zz==0 then
              entity[ii][1]=xx
              entity[ii][2]=yy
              grid[xx][yy]=2 -- // 2=a rock in the grid
              zz2=1
          end

          if zz==1 then

          end
      until zz2==1
  end

  --rem Place an apple,only check against rocks (nothing else exists)
  zz=1
  zz2=0
  repeat
    xx=Random(1,xsize-1)
    yy=Random(1,ysize-2)

    zz=grid[xx][yy]

    if zz==0 then
      applex=xx
      appley=yy
      grid[xx][yy]=3  --// 3=an apple
      zz2=1
    end

    if zz==1 then

    end
  until zz2==1
  --rem Remove loading page sprite
  DeleteSprite(98765)
end

function GameSpritesVisible()
  
  --Show Snake
  for i=1, 100 do
      SetSpriteVisible(i,1)
  end
  --Show Rocks
  count=1
  for i=rockstart, rockend do
    SetSpriteVisible(rocks[count],1)
    count = count + 1
  end
  --Show Apple
  SetSpriteVisible(500,1)

  --Show Left and Right
  if touch==1 then
      SetSpriteVisible(tright_s,1)
      SetSpriteVisible(tleft_s,1)
  end
  --Show Pause
  SetSpriteVisible(pause_s,1)

end

function ShowGame()
  SetTextColor(2,255,255,255,255)
  SetTextColor(3,255,255,255,255)
  SetTextColor(4,255,255,255,255)
  SetTextColor(5,255,255,255,255)
  SetTextPosition(2,20,0)
  SetTextPosition(3,86,0)
  SetTextPosition(4,315,0)
  SetTextPosition(5,415,0)
  SetTextVisible(2,1)
  SetTextVisible(3,1)
  SetTextVisible(4,1)
  SetTextVisible(5,1)
  SetSpriteVisible(501,0)
  SetSpritePosition ( 501, 0, -9999 )
  SetSpriteVisible(601,0) 
  SetSpritePosition ( 601, 480-50, -9999 )
  SetSpriteVisible(504,0)
  SetSpritePosition ( 504, 480-50, -9999 )
  SetSpriteVisible(503,1) 
  SetSpritePosition ( 503, 0, 0 )
  StopMusic()
  PlayMusic(2)
end

function Wait4Click()
  repeat
      click=GetPointerPressed()
      if click==1 and GetPointerX()>480-50 and GetPointerY()<50 then
       --rem pressed the OFF button in the title page
       --end
      end
      Sync()
  until click==1
  repeat
      click=GetPointerPressed()
      Sync()
  until click==0
end

function ShowMenu()
  SetTextVisible(2,0)
  SetTextVisible(3,0)
  SetTextVisible(4,0)
  SetTextVisible(5,0)
  SetSpriteVisible(touch_s,0)
  SetSpriteVisible(501,1)
  SetSpritePosition ( 501, 0, 0 )
  SetSpriteVisible(601,1) 
  SetSpritePosition ( 601, 480-50, 0 )
  SetSpriteVisible(504,0) 
  SetSpritePosition ( 504, 0, -9999 )
  SetSpriteVisible(503,0) 
  SetSpritePosition ( 503, 0, -9999 )
  StopMusic()
  PlayMusic(1)
end

function GameSpritesInvisible()
  --Hide Snake
  for i=1, 100 do
    SetSpriteVisible(i,0)
  end
  --Hide Rocks
  count=1
  for i=rockstart, rockend do
      SetSpriteVisible(rocks[count],0)
      count = count + 1
  end
  --Hide Diet Pill
  SetSpriteVisible(498,0)
  -- Hide Slow down
  SetSpriteVisible(slowid,0)
  -- Hide Gold Apple
  SetSpriteVisible(499,0)
  -- Hide Apple
  SetSpriteVisible(500,0)
  -- Hide Game Backdrop
  SetSpriteVisible(503,0) 
  SetSpritePosition ( 503, 0, -9999 )
  -- Hide Left and Right
  if touch==1 then
    SetSpriteVisible(tright_s,0)
    SetSpriteVisible(tleft_s,0)
  end
  --Hide Pause
  SetSpriteVisible(pause_s,0)
end

function LoadMusicFiles()
  LoadMusic(1,"hello.mp3") 	-- Main Game music
  LoadMusic(2,"hello2.mp3")	-- Main Menu music
  LoadMusic(3,"gameover.mp3")	-- Game Over music
  SetMusicFileVolume(1,40)
  SetMusicFileVolume(2,40)
  SetMusicFileVolume(3,40)

  LoadSound(1,"apple_chomp1.wav")	--eat apple
  LoadSound(2,"gapple.wav")	--eat golden apple
  LoadSound(3,"pill.wav")		--eat the pill
  LoadSound(4,"ooo.wav")
  LoadSound(5,"yummy.wav")
  LoadSound(6,"yuk.wav")
end

function LoadImages()
  t = "title.png"
  if touch == 1 then
      t = "title2.png"
  end

  LoadImage(6,t)
  CreateSprite(501,6)
  SetSpriteSize(501,480,320)
  SetSpritePosition(501,0,0)

  -- Load Game Background
  LoadImage(8,"background.png")
  CreateSprite(503,8)
  SetSpriteSize(503,480,320)
  SetSpriteColorAlpha(503,200)
  SetSpriteDepth(503,100)

  -- Load game over background
  LoadImage(9,"gameover.png")
  CreateSprite(504,9)
  SetSpriteSize(504,480,320)

  t = "touch.png"
  if touch == 0 then
      t = "click.png"
  end
  touch_i=LoadImage(t)
  touch_s=CreateSprite(touch_i)
  SetSpriteSize(touch_s,300,-1)
  SetSpritePosition(touch_s,475/2-(GetSpriteWidth(touch_s)/2),285)
  SetSpriteVisible(touch_s,0)

  -- 200911 - Power Off For AppUp
  LoadImage(601,"off.png")
  CreateSprite(601,601)
  SetSpritePosition(601,480-50,0)
  SetSpriteSize(601,50,50)

  if touch == 1 then
    tleft_i=LoadImage("turn_left.png")
    tright_i=LoadImage("turn_right.png")

    tleft_s=CreateSprite(tleft_i)
    tright_s=CreateSprite(tright_i)


    SetSpriteSize(tleft_s,scaler*2+2,-1)
    SetSpriteSize(tright_s,scaler*2+2,-1)

    SetSpritePosition(tleft_s,0,320-GetSpriteHeight(tleft_s))
    SetSpritePosition(tright_s,480-GetSpriteWidth(tright_s),320-GetSpriteHeight(tright_s))
    SetSpriteColorAlpha(tleft_s, 100 )
    SetSpriteColorAlpha(tright_s, 100 )
  end



  -- Load Snake segments
  LoadImage(1,"snake-head.png")
  CreateSprite ( 1, 1 )
  SetSpriteSize (1,scaler,-1)
  LoadImage(2,"snake-body.png")
  LoadImage(3,"snake-bend.png")
  LoadImage(4,"snake-tail.png")

  -- Load Apple
  LoadImage(5,"apple.png")
  CreateSprite(500,5)
  SetSpriteSize(500,scaler,-1)
  SetSpriteShape(500,1)
  entity[1][7]=500


  -- Load Golden Apple
  LoadImage(10,"applegold.png")
  CreateSprite(499,10)
  SetSpriteSize(499,scaler,-1)
  entity[2][7]=499


  -- Load Rock
  LoadImage(12,"rock.png")
  count=1
  for i=rockstart, rockend do
      rocks[count]=CreateSprite(12)
      SetSpriteSize (rocks[count],scaler,-1)
      entity[i][7]=rocks[count] -- Save sprite IDs
      count=count+1
  end

  -- Load Slow down images
  LoadImage(13,"slow.png")
  slowid=CreateSprite(13)
  SetSpriteSize(slowid,scaler,-1)
  entity[20][7]=slowid

  entity[3][7]=498

  -- Pill and it's animation
  CreateSprite(498,0)
  AddSpriteAnimationFrame ( 498, LoadImage ( "pill-00.png" ) )
  AddSpriteAnimationFrame ( 498, LoadImage ( "pill-01.png" ) )
  AddSpriteAnimationFrame ( 498, LoadImage ( "pill-02.png" ) )
  AddSpriteAnimationFrame ( 498, LoadImage ( "pill-03.png" ) )
  AddSpriteAnimationFrame ( 498, LoadImage ( "pill-04.png" ) )
  AddSpriteAnimationFrame ( 498, LoadImage ( "pill-05.png" ) )
  AddSpriteAnimationFrame ( 498, LoadImage ( "pill-06.png" ) )
  AddSpriteAnimationFrame ( 498, LoadImage ( "pill-07.png" ) )
  AddSpriteAnimationFrame ( 498, LoadImage ( "pill-08.png" ) )
  AddSpriteAnimationFrame ( 498, LoadImage ( "pill-09.png" ) )
  AddSpriteAnimationFrame ( 498, LoadImage ( "pill-10.png" ) )
  AddSpriteAnimationFrame ( 498, LoadImage ( "pill-11.png" ) )
  AddSpriteAnimationFrame ( 498, LoadImage ( "pill-12.png" ) )
  AddSpriteAnimationFrame ( 498, LoadImage ( "pill-13.png" ) )
  AddSpriteAnimationFrame ( 498, LoadImage ( "pill-14.png" ) )

  SetSpriteSize(498,scaler,-1)


  --Create Snake Segment Sprites
  for i=1, 100 do
    DeleteSprite(i)
    CreateSprite(i,2)
    SetSpriteSize (i,scaler,-1)
    SetSpritePosition(i,-50,-50)
  end

  -- Load Pause icon and Pause message
  pause_i=LoadImage("pause.png")
  pause_s=CreateSprite(pause_i)
  SetSpriteSize(pause_s,scaler,-1)
  SetSpritePosition(pause_s,450,0)

  pausetext_i=LoadImage("pause_text.png")
  pausetext_s=CreateSprite(pausetext_i)
  --rem setspritesize(pausetext_s,GetDeviceHeight()-(GetDeviceHeight()/4),-1)
  SetSpriteSize(pausetext_s,360,-1)
  SetSpritePosition(pausetext_s,240-(GetSpriteWidth(pausetext_s)/2),320/2-(GetSpriteHeight(pausetext_s)/2))
  SetSpriteVisible(pausetext_s,0)

  -- Particles
  LoadImage(7,"particle.png")
  CreateParticles(1,-100,-100)
  CreateParticles(2,-100,-100)
  SetParticlesDepth(1,5)
end

function MakeGameText()
  CreateText(2,"SCORE:")
  CreateText(3,"0")
  CreateText(4,"HIGH SCORE:")
  CreateText(5,"0")
  SetTextSize(2,14)
  SetTextSize(3,14)
  SetTextSize(4,14)
  SetTextSize(5,14)
  SetTextDepth( 2, 0 ) 
  SetTextDepth( 3, 0 ) 
  SetTextDepth( 4, 0 ) 
  SetTextDepth( 5, 0 )
end

function ClearGrid()
  for x = 0, xsize do
    grid[x] = {}
    for y = 0, ysize do
      grid[x][y] = 0
    end
  end 
end

--rem Fade in an entity
--rem s = entity number
--rem speed = speed of fade in
function fadein(s,speed)
  vis=0
  if entity[s][4]==1 then    --` Is this entity alive?
      if entity[s][5]==1 then --`Is it fading in?
          entity[s][6]=entity[s][6]+speed
          vis=entity[s][6]
          if entity[s][6]>=255 then
              entity[s][5]=2
              entity[s][6]=0
              vis=255
          end
      end
      if entity[s][5]==2 then
          vis=255
      end
  end
  SetSpriteColorAlpha(entity[s][7],vis)
end

--rem Fade out an entity
--rem s = entity number
--rem speed = speed of fade out
function fadeout(s,speed)
  vis=0
  if entity[s][4]==1 then   --` Is this entity alive?
      if entity[s][5]==0 then  --`Is this entity fading out?
          entity[s][6]=entity[s][6]+speed
          vis=255-entity[s][6]
          if entity[s][6]>=255 then
              entity[s][4]=0   --` Set to dead
              entity[s][5]=3   --` Mark as 0% visible
              entity[s][6]=0   --` Fade counter to zero
              vis=0
          end
          if entity[s][5]==3 then
            vis=0
          end
          SetSpriteColorAlpha(entity[s][7],vis)
      end
  end
end