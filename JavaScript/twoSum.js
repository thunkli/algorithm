var twoSum = function(nums, target) {
    var arr = [];
    var have = false;
    var len = nums.length;
    for (var i=0; i<len; i++) {
    	for (var j=0;j<len;j++){
    		if (((nums[i]+nums[j]) == target)&&i!=j){
                arr = [i,j];
                have = true;
                break;
            }
    	}
    	if (have) break;
    }
    return arr
};
console.log(twoSum([3,2,4],6))