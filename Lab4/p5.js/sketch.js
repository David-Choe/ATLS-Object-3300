// I originally wanted to create a 'DEFENDER' inspired dogfighting game, 
// but it turned out very similar to the game 'LUFTRAUSERS'
// utilizes p5.play
// next steps: dont draw enemies within some r of player
            //add ship sprites, death/exploding animations
            // add variety of enemies & powerups
// sugr7650@colorado.edu

//Joystick controls
var serial; //variable to hold an instance of the serial port library
var portName = 'COM3'; //fill in with YOUR port
var input_x = 0;
var input_y = 0;
var button = 10;

//Game variables
var player;
var bullets;
var shipImage; 
var bulletImage;
var cooldown = 100;
var maxCD = 100;

var enemy;
var enemyInterval;
var enemies;

var MARGIN = 40;
var SCENE_W = 4000;
var SCENE_H = 1660;
var enemyVision = 750;
var gameOver;
var score=0;
var highscore;

var flyingFrames = [
  {'name':'fly01', 'frame':{'x':0, 'y': 0, 'width': 100, 'height': 85}},
  {'name':'fly02', 'frame':{'x':101, 'y': 0, 'width': 100, 'height': 85}},
  {'name':'fly03', 'frame':{'x':201, 'y': 0, 'width': 100, 'height': 85}},
  {'name':'fly04', 'frame':{'x':301, 'y': 95, 'width': 100, 'height': 85}},
  {'name':'fly05', 'frame':{'x':401, 'y': 95, 'width': 100, 'height': 85}},
];

function preload() {
  // load in PNG sprites here instead of drawing squares
  crowSpriteSheet = loadSpriteSheet('https://i.imgur.com/qYVh3qX.png',flyingFrames)
  crowAnimation = loadAnimation(crowSpriteSheet)
}

function setup() {
  //setup for joystick
  serial = new p5.SerialPort(); //a new instance of serial port library

  //set up events for serial communication
  serial.on('connected', serverConnected);
  serial.on('open', portOpen);
  serial.on('data', serialEvent);
  serial.on('error', serialError);
  serial.on('close', portClose);

  //open our serial port
  serial.open(portName);
  

  c=createCanvas(windowWidth, windowHeight);
  c.position(0, 0);
  highscore = getItem('highscore');
  angleMode(DEGREES);

//create player 
  playerImage = createImage(32,32);
  playerImage.loadPixels();
    for (let i = 0; i < playerImage.width; i++) {
      for (let j = 0; j < playerImage.height; j++) {
        playerImage.set(i, j, color(255));
      }
    }
  playerImage.updatePixels();
  player = createSprite(width/2, height/2);
  player.setCollider('circle', 0, 0, 28);
  player.addImage(playerImage);
  player.maxSpeed = 10;
  player.friction=0.05;
  
//create ground image & sprite
  groundImage = createImage(100,100)
  groundImage.loadPixels();
    for (let i = 0; i < width; i++) {
      for (let j = 0; j < height; j++) {
        let c = color(random(0,255), random(0,255), random(0,255)); //new color every time page is refreshed (need to change this to every new game)
        groundImage.set(i, j, c);
      }
    }
  ground = createSprite(SCENE_W/2, SCENE_H+10, SCENE_W*2,100); 

//create bullet images
  bulletImage = createImage(12,12);
  bulletImage.loadPixels();
  for (let i=0; i<bulletImage.width; i++) {
    for (let j=0; j<bulletImage.height/3;j++) {
      bulletImage.set(i, j, color(0,255,0));
    }
  }
  bullets = new Group();  
  enemyBullets = new Group();
  
//create enemy image
  enemyImage = createImage(32,32);
  enemyImage.loadPixels();
  fastBoiImage = createImage(32,32);
  fastBoiImage.loadPixels();
    for (let i = 0; i < enemyImage.width; i++) {
      for (let j = 0; j < enemyImage.height; j++) {
        enemyImage.set(i, j, color(100, 50, 92));
      }
    }
  enemyImage.updatePixels();
  enemies = new Group();
  
// set starting condition 
  gameOver=true;
  updateSprites(false);
}

function draw() {
  background(50);
  
// ground square thingies placement  
  for (let i=1; i<20; i++){
    rect(map(i,1,20,1,SCENE_W),SCENE_H-50,25,50);
  }
  
// if game is over and click x then start new game  
  if (gameOver) {
    camera.position.x=width/2;
    camera.position.y=height/2;
    fill(255);
    text('Left & Right to rotate; up to accelerate, Press to shoot; Press to begin', windowWidth/2-45, windowHeight/2+32,150);
    text('Your Score:'+score, windowWidth/2-32, windowHeight/2-32,150)
    textSize(16)
    text('Highscore:'+ highscore, windowWidth/2-42, windowHeight/2-64,150)
    textSize(24)
    strokeWeight(4)
    text('Lab 4', windowWidth/2-96, windowHeight/2-84)
  }
  
  if(gameOver && button == 0) {
    newGame();
  }

  if(!gameOver) {
//kill if player hits the ground
    if (player.position.y >= SCENE_H) {
      player.position.y=SCENE_H;
      die();
    }
// in case of player flying too high, change y velocity to bounce back   
    if (player.position.y <= 0) {
      player.velocity.y+=15;
    }    

//wrapping screen
    for(var i=0; i<allSprites.length; i++) {
      var s = allSprites[i];
      if(s.position.x<-MARGIN) {
        s.position.x = SCENE_W+MARGIN;
      }
      if(s.position.x>SCENE_W+MARGIN) {
        s.position.x = -MARGIN; 
      }
    }

// camera controls    
    if (camera.position.y<=SCENE_H-(windowHeight/2) && camera.position.y>=0+(windowHeight/2)) {
      camera.position.x=player.position.x-(3*player.velocity.x);
      camera.position.y=player.position.y-(3*player.velocity.y);
    }
    if (camera.position.y>SCENE_H-(windowHeight/2) || camera.position.y<0+(windowHeight/2)) {
      camera.position.x=player.position.x-(3*player.velocity.x);
      if (player.position.y<=SCENE_H-(windowHeight/2) && player.position.y>=0+(windowHeight/2)) {
        camera.position.x=player.position.x-(3*player.velocity.x);
        camera.position.y=player.position.y-(3*player.velocity.y);
      }
    }    

// movement control  
    if(input_x == 0 || input_x <= 50) {
      player.rotation += 2;
    }
    if(input_x == 200 || input_x >= 150) {
      player.rotation -= 2;
    }
    if(input_y > 150) {
        player.addSpeed(1,player.rotation)
    }
  
//shooting
    if(button == 0) {
      //set the attack speed of the button so it's not a machine gun
      if(cooldown == maxCD){
        var bullet = createSprite(player.position.x, player.position.y);
        bullet.addImage(bulletImage);
        bullet.setSpeed(10+player.getSpeed(), player.rotation);
        bullet.life = 20;
        bullet.rotateToDirection = true;
        bullets.add(bullet);
        bulletImage.updatePixels();
        cooldown = 0;
      }
      else{
        cooldown+=20;
      }
    } 

// set enemy behavior    
    for (let i=0; i<enemies.length;i++) {
      en = enemies[i];
      en.bounce(enemies)
      en.life = 3;
      //enemies fly slower when the player is some distance away
      if (abs(en.position.x-player.position.x)>enemyVision) {
        
        en.attractionPoint(0.05, player.position.x+random(10,100), player.position.y+random(10,100))
      }
      // when player is within "vision" of the enemy, it accelerates faster
      else {
        en.attractionPoint(0.1, player.position.x+random(10,100), player.position.y+random(10,100))
      }
      
    }
    enemies.overlap(bullets, enemyHit)
    enemies.overlap(player, die)
    
  }//end of !gameover if loop
    
  print(score);
  drawSprites(); 
  
} //end of draw loop


function drawEnemy() {
  if (enemies.length<=50) {
    var ax = random(50, SCENE_W-50);
    var ay = random(50, SCENE_H-50);
    enemy = createSprite(ax,ay);
    enemy.setCollider('circle', 0, 0, 28);
    enemy.addImage(enemyImage);
    enemy.addAnimation('flying', crowAnimation)
    enemy.rotateToDirection=true;
    enemy.maxSpeed = 7;
    enemies.add(enemy); 
  } 
}

function enemyHit(enemy, bullet) {
  for (let i=0; i<enemies.length;i++) {
    en = enemies[i];  
    if (en != enemy) {
      if (en.position.x <= enemy.position.x+enemyVision && en.position.x <= enemy.position.y+enemyVision) {
        en.velocity.x = -2* abs(en.position.x-enemy.position.x)
        en.velocity.y = -2 * abs(en.position.y-enemy.position.y)
      } 
    }
  }
  enemy.remove();
  bullet.remove();
  if (enemy.maxSpeed==8) {
    score+=5; //need to fix this, still only adding 1
  }
  else {
    score++
  }
  if (score>highscore) {
    highscore = score;
  }
}

function die() {
  enemies.removeSprites();
  bullets.removeSprites();
  updateSprites(false);
  gameOver = true;
  gravity=0;
  player.velocity.x=0;
  player.velocity.y=0;
  clearInterval(enemyInterval);
  storeItem('highscore', highscore)
}

function newGame() {
  gameOver = false;
  enemies.removeSprites();
  bullets.removeSprites();
  updateSprites(true);
  camera.on();
  player.position.x = windowWidth/2;
  player.position.y = windowHeight/2;
  player.rotation=0;
  gravity=0.3;
  enemyInterval = setInterval(drawEnemy, 1000); //call function to draw enemy every 1s
  score=0;
  drawSprites();
}

//Joystick controls
function serverConnected(){
  console.log('connected to the server');
}

function portOpen(){
  console.log('the serial port opened!');
}

//THIS IS WHERE WE RECEIVE DATA!!!!!!
//make sure you're reading data based on how you're sending from arduino
function serialEvent(){
	//receive serial data here
  var data = serial.readLine();
  if(data === "")return;
  var split = data.split(',');
  ///console.log(split[0],split[1],split[2]);
  button = split[0];
  input_x = map(split[1], 0,1023,0,200);
  input_y = map(split[2], 0,1023,0,200);
  //console.log(button, input_x, input_y);
}

function serialError(err){
  console.log('something went wrong with the port. ' + err);
}

function portClose(){
  console.log('the port was closed');
}

// get the list of ports:
function printList(portList) {
 // portList is an array of serial port names
 for (var i = 0; i < portList.length; i++) {
 // Display the list the console:
 print(i + " " + portList[i]);
 }
}
