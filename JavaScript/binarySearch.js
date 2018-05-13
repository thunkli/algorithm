// 二分查找，前提是数组为有序数组
function binarySearch(target, arr) {
    let start = 0;
    let end = arr.length - 1;

    while (start <= end) {
        let mid = parseInt(start + (end - start) / 2);
        if (target == arr[mid]) {
            return mid;
        } else if (target > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}
console.log(binarySearch('3',[0,1,2,3,4,5]))