var player;
var objective;

function startGame() {    
    player = new component("20", "20", "blue", 10, 420);
    objective = new component("20px", "Consolas", "black", 350,40, "text")
    canvasObject.start();
}

var canvasObject = {
    canvas : document.createElement("canvas"),
    start : function(){
        this.canvas.width = 720;
        this.canvas.height = 480;
        this.context = this.canvas.getContext("2d");
        document.getElementById("mainbody").insertBefore(this.canvas, document.getElementById("controls"));
        this.interval = setInterval(refreshCanvas, 50);
    },
    clear : function() {
        this.context.clearRect(0, 0, this.canvas.width, this.canvas.height);
    }
}

function component(width,height,color,x,y,type){
    this.type;
    this.width = width;
    this.height = height;
    this.x = x;
    this.y = y;
    this.speedX = 0;
    this.speedY = 0;
    this.gravityAccel = 1.98;
    this.gravitySpeed = 0;
    this.recoil = 0.02;
    this.update = function(){

        ctx = canvasObject.context;
        if(type=="text"){
            ctx.font = this.width + " " + this.height; // Width is size of font and height is font family
            ctx.fillStyle = color;
            ctx.fillText(this.text, this.x, this.y);
        }
        ctx.fillStyle = color;
        ctx.fillRect(this.x,this.y,this.width,this.height);
    }
    this.newPos = function(){        
        this.x += this.speedX;
        this.gravitySpeed += this.gravityAccel;            
        this.y += this.speedY + this.gravitySpeed;
        this.boundsCheck();
    }
    this.boundsCheck = function(){
        var bottom = canvasObject.canvas.height - this.height;
        if (this.y > bottom){
            this.gravitySpeed = -(this.gravitySpeed*this.recoil); // Go up on the canvas
            this.speedY = 0;
            this.y = bottom;
        }
    }
}

document.body.onkeydown = function(event){
    event = event || window.event;
    var keycode = event.charCode || event.keycode;
    switch(keycode){
        case 37:
            moveLeft();
            break;
        case 38:
            playerJump();
            break;
        case 39:
            moveRight();
            break;
        default:
            return;
    }
    event.preventDefault();
}
function refreshCanvas(){
    canvasObject.clear();
    objective.text ="Get to the end of the map";
    objective.update();
    player.newPos();
    player.update();
}
function moveLeft(){
    player.speedX -= 5;
}

function moveRight(){
    player.speedX += 5;
}

function playerJump(){
    player.speedY -= 15;
}
