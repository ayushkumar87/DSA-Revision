// bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int row,col,st=0,mid,end=matrix.size()*matrix[0].size()-1;
//         while(st<=end){
//             mid=end+(st-end)/2;
//             row=mid/matrix[0].size();
//             col=mid%matrix[0].size();

//             if(matrix[row][col]==target){
//                 return true;
//             }
//             else if(matrix[row][col]<target){
//                 st=mid+1;
//             }
//             else{
//                 end=mid-1;
//             }
//         }
//         return false;
//     }