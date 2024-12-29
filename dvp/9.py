#9
import plotly.express as px
import pandas as pd
import random as rdm
df = pd.DataFrame({
    'x': [rdm.randint(0, 10) for _ in range(5)],
    'y': [rdm.randint(0, 10) for _ in range(5)],
    'z': [rdm.randint(0, 10) for _ in range(5)]
})
fig1 = px.scatter_3d(df, x='x', y='y', z='z', title="Random Data 3D Scatter Plot")
fig.write_html("fig.html")
fig1.show()