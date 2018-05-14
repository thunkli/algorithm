function Quicksort(sortMe) {
    var sorted = [];
    var _this = this;

    this.sortMe = sortMe.slice(0);

    this.getList = function () {
        return _this.sortMe;
    };

    this.getPivot = function (left, right) {
        return Math.floor((left + right) / 2);
    };

    this.swap = function (positionOne, positionTwo) {
        var temp = this.sortMe[positionOne];

        this.sortMe[positionOne] = this.sortMe[positionTwo];
        this.sortMe[positionTwo] = temp;
    };

    this.partition = function (leftPointer, rightPointer) {
        var pivot = _this.getPivot(leftPointer, rightPointer);

        while (leftPointer <= rightPointer) {

            while (_this.sortMe[leftPointer] < _this.sortMe[pivot]) {
                leftPointer++;
            }

            while (_this.sortMe[rightPointer] > _this.sortMe[pivot]) {
                rightPointer--;
            }

            if (leftPointer <= rightPointer) {
                _this.swap(leftPointer, rightPointer);
                leftPointer++;
                rightPointer--;
            }
        }

        return leftPointer;
    };

    this.sort = function (leftPointer, rightPointer) {
        if (Math.abs(leftPointer - rightPointer) >= 1) {
            var index = _this.partition(leftPointer, rightPointer);

            if (leftPointer < index - 1) {
                _this.sort(leftPointer, index - 1);
            }

            if (index < rightPointer && rightPointer < 3) {
                _this.sort(index, rightPointer);
            }
        }
    };

    this.sort(0, this.sortMe.length - 1);
}

console.log(Quicksort([2, 8, 1, 2, 1, 32, 90, 2, 1]))