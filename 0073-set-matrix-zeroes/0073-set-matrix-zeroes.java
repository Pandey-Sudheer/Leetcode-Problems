class Solution {
    public void setZeroes(int[][] matrix) {
      int n = matrix.length;
      int m = matrix[0].length;

    //   make the every  row and column false intially
      boolean row[] = new boolean[n];
      boolean col[] = new boolean[m];

    //   check whether item of row or column have '0' item or not if yes then set the item true
      for( int i=0; i<n; i++)
      {
        for( int j=0; j<m; j++)
        {
            if( matrix[i][j] == 0 )
            {
                row[i] = true;
                col[j] = true;
            }
        }
      }
    //   making the '0' of its entire row thoose have true value
      for( int i=0; i<n; i++)
      {
        if( row[i])
        {
            for( int j=0; j<m; j++)
            {
                matrix[i][j] = 0;
            }
        }
      }
//   making the '0' of its entire column thoose have true value
      for( int j=0; j<m; j++)
      {
        if( col[j])
        {
            for( int i=0; i<n; i++)
            {
                matrix[i][j] = 0;
            }
        }
      }
    }
}