size(400,400);
// Put ten numbers into an array nums
int [] nums = {1,3,7,5,12,4,11,22,1,9};
int total = 0;
for (int counter=0; counter<nums.length; counter=counter+1){
    total = total + nums[counter];
 }
fill(0);
text(total,50,50);
// Now to find the largest positive value.
int max=nums[0];
for (int i=1; i<nums.length; i++) {
    if (nums[i]>max) {
        max=nums[i];
    } 
}
text("The largest value is "+max,20,100);
// (We can find the minimum in the same way)
// But let's do it at the same time.
int min=nums[0]; 
max=nums[0];

for (int i=1; i<nums.length; i++) {
    if (nums[i]>max) {
        max=nums[i];
    }else if(nums[i]<min) {
        min=nums[i];
    }
}
text("The smallest value is "+min,20,150);
// Now let's use this!
//size(400,400);

for (int circles=0;circles < nums.length; circles++) {
    // Let's make it easier to see.
    int rad = 6*nums[circles];
    if (nums[circles]==min) {
        noStroke();
        fill(255,0,0);
    } else if (nums[circles]==max) {
        stroke(255,0,0);
        noFill();
    } else {
        noFill();
        stroke(0);
    }
    ellipse(width/2,height/2,rad,rad);
}