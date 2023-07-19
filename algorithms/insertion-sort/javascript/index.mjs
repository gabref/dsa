import { insertionSort, insertionSort2 } from "./insertion-sort.mjs";

let arr1 = [9, 7, 5, 3, 1];
console.log('arr 1', arr1);
console.log('arr 1', insertionSort(arr1));

let arr2 = [2, 5, 6,3 , 6, 7, 7, 7];
console.log('arr 2', arr2);
console.log('arr 2', insertionSort(arr2));

arr1 = [9, 7, 5, 3, 1];
console.log('arr 1', arr1);
console.log('arr 1', insertionSort2(arr1));

arr2 = [2, 5, 6,3 , 6, 7, 7, 7];
console.log('arr 2', arr2);
console.log('arr 2', insertionSort2(arr2));
