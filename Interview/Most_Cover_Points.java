
/*
 *在数轴上有a[0],a[1],a[2],.....,a[n-1]个点，
 *有一根长度为L 的尺子，最多能覆盖多少个点？  
 */
public class Most_Cover_Points {
	int[] points =  {1,4,10,12,12,12,12,13,20,22,23,24};
	int L = 3;
	
	public void totalNum (){
		int num = 0;
		int totalnumber = 0;
		int len = points.length;
		int sublen = 0;
		for(int i=0; i < len; i++) {
			num = 0;
			for(int j=i; j< len; j++ ) {
				sublen = points[i] + L;
				System.out.println("sublen : " + sublen);
				if(points[j] <= sublen) {
					System.out.println("points[j] : " + points[j]);
					num++;
				} else {
					j = len-1;
				}
			}
			if(totalnumber < num) {
				totalnumber = num;
				System.out.println("totalnumber : " + totalnumber);
			}
		}
		System.out.println("最多能覆盖"+ totalnumber +"个点");
	}
}
