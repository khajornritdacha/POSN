 int lim = (1<<K);
    while(Q--){
        int u,v;
        cin >> u >> v;
        if(u > v)
            swap(u, v);
        int ans = 1e9;
        if((u <= lim and v <= lim) or (u >= lim and v >= lim))
            ans = dep[u]+dep[v]-2*dep[lca(u, v)];
        for(int i=1, T1 = (u >= lim ? LL : 0); i<=LL; i++){
            for(int j=1, T2 = (v >= lim ? LL : 0); j<=LL; j++){
                int tmp = dep[u]+dep[L[T1+i]]-2*dep[lca(u, L[T1+i])] + dis[T1+i][T2+j] + dep[L[T2+j]]+dep[v]-2*dep[lca(v, L[T2+j])];
                ans = min(ans, tmp);
                if(DEBUG){
                    printf("--------------------------\n");
                    printf("IJ :%d, %d\n", i, j);
                    printf("UV :%d, %d\n", u, v);
                    printf("T1L1 :%d, %d\n", T1, L[T1+i]);
                    printf("T2L2 :%d, %d\n", T2, L[T2+j]);
                    printf("Lca : %d, %d\n", lca(u, L[T1+i]), lca(v, L[T2+j]));
                    printf("TMP : %d\n", tmp);
                    printf("--------------------------\n");
                }
            }
        }
        cout << ans << "\n";
    }
}
