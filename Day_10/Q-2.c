int* intersect(int* nums1, int size1, int* nums2, int size2, int* returnSize) {
   
    int *res = (int*)malloc(sizeof(int) * (size1 < size2 ? size1 : size2));

    int k = 0;

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (nums1[i] == nums2[j]) {
                res[k++] = nums1[i];
                nums2[j] = -1;  
                break;
            }
        }
    }

    *returnSize = k;
    return res; 
}  

