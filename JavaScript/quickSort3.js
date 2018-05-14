// 速度最慢慎用
const qsort = arr => arr.length <= 1 ? arr : qsort(arr.filter(x => x < arr[0]))
    .concat(arr.filter(x => x === arr[0]))
    .concat(qsort(arr.filter(x => x > arr[0])));
console.log(qsort([2, 8, 1, 2, 1, 32, 90, 2, 1]))